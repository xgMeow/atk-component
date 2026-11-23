/*
 * 把「面板同步」开关（#nav-sync）从左树挪到顶部导航栏，钉在搜索框左边。
 *
 * 背景：Doxygen 把这个按钮生成在 #nav-tree-contents 的最上面（position:absolute;
 * top:0; right:0），正好压在树的第一条目录上，鼠标扫过时那一块会盖住条目文字，
 * 类名一长就明显了。
 *
 * 做法：DOM 就绪后把 #nav-sync 装进 .atk-nav-sync 容器，再挂到当前可见的那条
 * 导航栏上——宽屏是 #main-nav，窄屏（<768px）菜单收起来后是 #main-nav-mobile，
 * 两条栏里搜索框都在右侧。容器按搜索框的实测位置算 right，于是按钮始终紧挨在
 * 搜索框左边。
 *
 * 坐标必须写在外层容器上：navtree.js 的 adjustSyncIconPosition() 会按滚动条宽度
 * 改写 #nav-sync 自己的 style.right，直接给 #nav-sync 写坐标会被覆盖。
 *
 * 点击切换与状态类名全部沿用 navtree.js，这里不复制导航逻辑；脚本没跑起来时按钮
 * 仍留在树里的原位，只是不移动。
 *
 * 提示气泡：navtree.js 只在内部图标上留了 title（「点击 关闭 面板同步」），原生
 * tooltip 慢半拍、也不说清这块开关管什么，而且那层图标被样式压成透明热区后提示时灵
 * 时不灵。所以这里自绘一个 .atk-nav-sync__tip：悬停 / 键盘聚焦立即出现，分两行写清
 * 「面板同步：开/关」和「点了会发生什么」。title 一律摘掉，免得两套提示一起弹；
 * 无障碍名称改由 aria-label 提供。
 */
(function () {
  'use strict';

  var GAP = 12;          // 按钮与搜索框之间的距离

  var sync = null;       // #nav-sync（按钮本体，由 Doxygen 生成）
  var dock = null;       // .atk-nav-sync 定位容器
  var tip = null;        // .atk-nav-sync__tip 提示气泡（自绘，替代原生 title）

  // 提示文案：[标题, 说明]；navtree.js 用 .sync 类表示同步开启
  var TIP_ON = ['面板同步：开', '左侧目录跟随页面滚动 · 点击暂停'];
  var TIP_OFF = ['面板同步：关', '左侧目录不再跟随 · 点击恢复'];

  // 当前真正显示的那条导航栏（另一条在断点外是 display:none，高度为 0）
  function visibleBar() {
    var mobileBar = document.getElementById('main-nav-mobile');
    if (mobileBar && mobileBar.offsetHeight > 0) { return mobileBar; }
    var desktopBar = document.getElementById('main-nav');
    if (desktopBar && desktopBar.offsetHeight > 0) { return desktopBar; }
    return null;
  }

  function position() {
    if (!dock || !dock.parentNode) { return; }
    var host = dock.parentNode;
    var box = document.getElementById('MSearchBox');
    var right = null;
    if (box && host.contains(box)) {
      var hostRect = host.getBoundingClientRect();
      var boxRect = box.getBoundingClientRect();
      if (hostRect.width > 0 && boxRect.width > 0) {
        right = Math.round(hostRect.right - boxRect.left + GAP);
      }
    }
    // 量不到（搜索框还没布局）就退回样式表里的默认 right，不写死一个可能对不上的数字
    dock.style.right = right === null ? '' : right + 'px';
  }

  // 气泡结构：[标题][说明]，文字在 refresh() 里按当前状态改写
  function buildTip() {
    tip = document.createElement('span');
    tip.className = 'atk-nav-sync__tip';
    tip.id = 'atk-nav-sync-tip';
    tip.setAttribute('role', 'tooltip');
    tip.appendChild(document.createElement('b'));
    tip.appendChild(document.createElement('span'));
    dock.appendChild(tip);
    sync.setAttribute('aria-describedby', 'atk-nav-sync-tip');
  }

  // 同步状态（.sync）与内部 innerHTML 都会变，统一在这里重算文案；
  // 顺便摘掉 navtree.js 写在内部图标上的 title，否则原生气泡会和自绘的同时弹出。
  function refresh() {
    if (!sync || !tip) { return; }
    var titled = sync.querySelectorAll('[title]');
    for (var i = 0; i < titled.length; i += 1) { titled[i].removeAttribute('title'); }

    var text = sync.classList.contains('sync') ? TIP_ON : TIP_OFF;
    tip.firstChild.textContent = text[0];
    tip.lastChild.textContent = text[1];
    sync.setAttribute('aria-label', text[0] + '，' + text[1]);
  }

  var refreshQueued = false;
  function refreshSoon() {
    if (refreshQueued) { return; }
    refreshQueued = true;
    var run = function () { refreshQueued = false; refresh(); };
    if (window.requestAnimationFrame) { window.requestAnimationFrame(run); }
    else { window.setTimeout(run, 0); }
  }

  function apply() {
    var host = visibleBar();
    if (!host) { return; }              // 没有导航栏的页面保持树里的原位
    if (dock.parentNode !== host) { host.appendChild(dock); }
    if (sync.parentNode !== dock) { dock.appendChild(sync); }
    position();
  }

  function schedule() {
    if (window.requestAnimationFrame) { window.requestAnimationFrame(apply); }
    else { apply(); }
  }

  function init() {
    sync = document.getElementById('nav-sync');
    if (!sync) { return; }              // 没有树栏的页面不生成 #nav-sync

    dock = document.createElement('div');
    dock.className = 'atk-nav-sync';
    document.body.appendChild(dock);

    // 原来是个不可聚焦的 <div>，补上键盘可达（Enter / 空格触发原生 click）
    if (!sync.hasAttribute('tabindex')) { sync.setAttribute('tabindex', '0'); }
    if (!sync.hasAttribute('role')) { sync.setAttribute('role', 'button'); }
    sync.addEventListener('keydown', function (e) {
      if (e.key === 'Enter' || e.key === ' ') {
        e.preventDefault();
        sync.click();
      }
    });

    buildTip();
    apply();
    refresh();

    // 点一下、按 Enter，navtree.js 会改 .sync 类并重写 innerHTML（连带恢复 title），
    // 用观察器兜住所有变体，不依赖两个脚本的点击监听谁先注册。
    sync.addEventListener('click', refreshSoon);
    if (window.MutationObserver) {
      new MutationObserver(refreshSoon).observe(sync, {
        childList: true,
        subtree: true,
        attributes: true
      });
    }

    // initMenu() 与 initNavTree() 都在 DOMContentLoaded 里跑，首帧之后再量一次；
    // 跨断点时两条导航栏切换可见性，resize 时重新选宿主。
    schedule();
    window.addEventListener('load', position);
    window.addEventListener('resize', schedule);
    // Web 字体可能晚于首屏，字宽变化会连带改变搜索框宽度
    if (document.fonts && document.fonts.ready) { document.fonts.ready.then(position); }
  }

  document.addEventListener('DOMContentLoaded', init);
})();
