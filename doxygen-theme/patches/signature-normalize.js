/**
 * 成员签名排版归一化（Doxygen 1.17.0 定制补丁，说明见 doxygen-theme/README.md）
 *
 * Doxygen 把一条成员签名拆在表格单元格里输出：
 *
 *   汇总表  <td class="memItemLeft">IAccessConstraint *&#160;</td>
 *           <td class="memItemRight">AddConstraint (EAccessConstraints eConstraint)</td>
 *   签名条  <td class="memname">IAccessConstraint * AddConstraint </td><td>(</td>
 *           <td class="paramtype">EAccessConstraints</td><td class="paramname">eConstraint</td>
 *           <td>)</td> ...
 *
 * 于是页面上显示成 `IAccessConstraint * AddConstraint ( EAccessConstraints eConstraint )`：
 * `*`、`(`、`)`、`<`、`>` 两边都挂着空格。选中复制时，单元格之间还会带上 tab，
 * 返回类型末尾那个 `&#160;`（NBSP，U+00A0）也会原样进剪贴板——粘进源码里是非法字符
 * （MSVC C2018 / GCC stray '\302'）。
 *
 * 这个脚本做两件事：
 *   1. 页面加载后重排签名区的文本节点，把空白改成 C++ 的写法：
 *      `*` `&` 贴类型、`(` 贴函数名、`)` `,` 前不留空格、模板尖括号内侧不留空格、
 *      参数类型和参数名之间留一个空格；
 *   2. 复制时（Ctrl+C / 右键复制都走 copy 事件）把选区纯文本里的 tab、NBSP 换成
 *      普通空格，并把同一条签名折起来的参数行合并成一行。
 *
 * 只作用于签名区（汇总表两列 / 详细说明的签名条），正文和参数说明表一律不碰。
 * 详细说明里签名条单元格之间的 2px 间隙由 style.css 的「成员签名排版」一节去掉；
 * 这里只负责文本，不管单元格布局。
 */
(function () {
  'use strict';

  // 签名区：成员汇总表的两列 + 成员详细说明里的签名条
  var SIG_CELLS = 'td.memItemLeft, td.memItemRight, .memproto table.memname td';
  // 复制时只接管上面这些；成员列表页（*-members.html）的签名在 td.entry 里，
  // 那一页只重排显示、不改复制行为（整行复制时还带着所属类名，不适合当签名用）
  var COPY_CELLS = SIG_CELLS;
  var MEMBER_LIST = /-members\.html$/.test(window.location.pathname);
  if (MEMBER_LIST) SIG_CELLS += ', td.entry';

  // 空白重排规则（按顺序生效）。
  // 注意：JS 的 \s 包含 NBSP（U+00A0），这样返回类型末尾的 NBSP 也能参与匹配，
  // 但它本身不会被替换成普通空格——汇总表靠它在两列之间留出那个空格。
  var SPACE_RUN        = /[ \t]+/g;
  var SPACE_BEFORE_PUNCT = /\s+([,;)\]>])/g;   // ) , ] > 前不留空格
  var SPACE_AFTER_OPEN   = /([<(\[])\s+/g;     // < ( [ 后不留空格
  var SPACE_BEFORE_STAR  = /\s+([*&]+)/g;      // * & 贴住类型
  var SPACE_AFTER_STAR   = /([*&]+)\s+(?=\S)/g;// * & 后最多一个空格（行尾不动）
  var SPACE_BEFORE_PAREN = /\s+\(/g;           // 函数名和 ( 之间不留空格

  function respace(text) {
    return text
      .replace(SPACE_RUN, ' ')
      .replace(SPACE_BEFORE_PUNCT, '$1')
      .replace(SPACE_AFTER_OPEN, '$1')
      .replace(SPACE_BEFORE_STAR, '$1')
      .replace(SPACE_AFTER_STAR, '$1 ')
      .replace(SPACE_BEFORE_PAREN, '(');
  }

  // 单元格首尾的普通空格/制表符去掉；NBSP 保留（汇总表左列靠它撑开列间距，
  // 删掉会让 `IAccessConstraint*` 和函数名贴在一起）
  function trimCellEnds(cell) {
    var texts = [];
    var walker = document.createTreeWalker(cell, NodeFilter.SHOW_TEXT, null);
    while (walker.nextNode()) texts.push(walker.currentNode);
    if (!texts.length) return;

    var first = texts[0];
    var last = texts[texts.length - 1];
    first.data = first.data.replace(/^[ \t]+/, '');
    last.data = last.data.replace(/[ \t]+$/, '');
  }

  function normalizeCell(cell) {
    var nodes = [];
    var walker = document.createTreeWalker(cell, NodeFilter.SHOW_TEXT, null);
    while (walker.nextNode()) nodes.push(walker.currentNode);
    if (!nodes.length) return;

    for (var i = 0; i < nodes.length; i++) {
      var before = nodes[i].data;
      var after = respace(before);
      if (after !== before) nodes[i].data = after;
    }
    trimCellEnds(cell);
  }

  function init() {
    var cells = document.querySelectorAll(SIG_CELLS);
    for (var i = 0; i < cells.length; i++) normalizeCell(cells[i]);
  }

  // ---------- 复制时清洗纯文本 ----------

  function elementOf(node) {
    if (!node) return null;
    return node.nodeType === 1 ? node : node.parentElement;
  }

  function inSignatureArea(node) {
    var el = elementOf(node);
    return !!(el && el.closest(COPY_CELLS));
  }

  function closestProto(node) {
    var el = elementOf(node);
    return el ? el.closest('.memproto') : null;
  }

  /**
   * @param {string} text  选区纯文本
   * @param {boolean} oneSignature 选区是否整段落在同一个签名条里（多行参数要并成一行）
   */
  function tidyClipboardText(text, oneSignature) {
    var t = text.replace(/\u00A0/g, ' ').replace(/\r/g, '');
    if (oneSignature) t = t.replace(/[ \t]*\n[ \t]*/g, ' ');
    t = t.split('\n').map(function (line) {
      return respace(line).replace(/^ +| +$/g, '');
    }).join('\n');
    return t.replace(/\n{3,}/g, '\n\n').trim();
  }

  document.addEventListener('copy', function (event) {
    var sel = window.getSelection();
    if (!sel || !sel.rangeCount || sel.isCollapsed) return;
    if (!event.clipboardData) return;
    // 选区的两端都在签名区才接管；从签名拖到正文说明区的选择保持浏览器默认行为
    if (!inSignatureArea(sel.anchorNode) || !inSignatureArea(sel.focusNode)) return;

    var range = sel.getRangeAt(0);
    var startProto = closestProto(range.startContainer);
    var endProto = closestProto(range.endContainer);
    var text = tidyClipboardText(sel.toString(), !!startProto && startProto === endProto);
    if (!text) return; // 只选到空白就别接管，免得把剪贴板清空

    event.clipboardData.setData('text/plain', text);
    event.preventDefault();
  }, true);

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
  } else {
    init();
  }
})();
