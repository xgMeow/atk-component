/*
 * 左树「整行可点」补丁。
 *
 * 背景：Doxygen 的 navtree.js 只把条目文字包在 <a> 里（展开箭头也是独立的 <a>），
 * 行内其余区域——左侧缩进槽、箭头槽的空白、左右 6px 内边距——都是死区。
 * 但 :hover 时整行会变灰，视觉上承诺了「这一整行能点」，点下去却没反应。
 *
 * 做法：事件委托。点在 <a> 上就放行（文字跳转、箭头展开都走原生逻辑）；
 * 点在本行其它位置时，转发成对文字 <a> 的 .click()——这样 hash 锚点、
 * storeLink() 记住的树状态、nolink 节点的「点一下展开」全都自动复用，
 * 不需要在这里重写一遍导航逻辑。
 */
(function () {
  'use strict';

  function anchorOf(el) {
    var item = el.closest('#nav-tree .item');
    return item ? item.querySelector('.label a') : null;
  }

  // 空白区点击：转发给文字 <a>（正常跳转），带修饰键时按新标签页打开
  document.addEventListener('click', function (e) {
    var t = e.target;
    if (!t || !t.closest) { return; }
    if (t.closest('a')) { return; }            // 文字链接 / 展开箭头：原生行为
    var link = anchorOf(t);
    if (!link) { return; }
    var href = link.getAttribute('href') || '';
    if ((e.ctrlKey || e.metaKey || e.shiftKey) && href && href.indexOf('javascript:') !== 0) {
      window.open(href, '_blank');
      return;
    }
    link.click();
  });

  // 中键点空白区：和点文字中键一致，新标签页打开
  document.addEventListener('auxclick', function (e) {
    if (e.button !== 1) { return; }
    var t = e.target;
    if (!t || !t.closest || t.closest('a')) { return; }
    var link = anchorOf(t);
    if (!link) { return; }
    var href = link.getAttribute('href') || '';
    if (!href || href.indexOf('javascript:') === 0) { return; }
    e.preventDefault();
    window.open(href, '_blank');
  });
})();
