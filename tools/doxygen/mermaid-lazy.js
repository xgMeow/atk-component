/* Mermaid 按需加载（替代 Doxygen 输出中的 Mermaid 占位符）
 *
 * Doxygen 1.17.0 默认 MERMAID_RENDER_MODE = 客户端渲染，输出的是：
 *
 *   <script type="module">
 *   import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@11/dist/mermaid.esm.min.mjs';
 *   mermaid.initialize({ startOnLoad: true, theme: ... });
 *   </script>
 *
 * 两个问题：
 *   1. 模块脚本是「延迟脚本」，DOMContentLoaded 要等它执行完。mermaid 的依赖图是一串
 *      按需 import 的 chunk，每个都要单独走一次网络；国内访问 jsdelivr 时这一段能到几秒。
 *      而左侧树（navtree.js 的 initResizable）是在 DOMContentLoaded 里才建出来的 ——
 *      于是每次点左树，正文都先按「没有左栏」排一遍、撑满整行，等 CDN 回来才缩回去。
 *   2. Doxygen 1.17.0 会把这段脚本输出到**每个页面**，即使一页 Mermaid 图都没有
 *      （已知问题），对纯 C++ 接口文档来说完全是白等。
 *
 * 这里换成普通脚本（不阻塞解析 / 不延迟 DOMContentLoaded），并且只在页面里真的存在
 * .mermaid 时才去 import。当前文档没有 Mermaid 图，所以这个文件实际上不会发起任何请求；
 * 以后用 \mermaid 写图时行为仍然不变，只是图会比正文晚一点出现。
 *
 * 想换自托管或换版本，改 MERMAID_URL 即可（对应 Doxygen 的 MERMAID_JS_URL 配置）。
 */
(function () {
  var MERMAID_URL = 'https://cdn.jsdelivr.net/npm/mermaid@11/dist/mermaid.esm.min.mjs';

  function boot() {
    var nodes = document.querySelectorAll('.mermaid');
    if (!nodes.length) return;
    import(MERMAID_URL)
      .then(function (mod) {
        var mermaid = mod.default;
        mermaid.initialize({
          startOnLoad: false,
          // 与 Doxygen 生成的初始化代码保持一致：跟随系统深浅色
          theme: window.matchMedia('(prefers-color-scheme: dark)').matches ? 'dark' : 'default',
        });
        return mermaid.run({ nodes: Array.prototype.slice.call(nodes) });
      })
      .catch(function (err) {
        // 加载失败只影响图，不影响导航与正文
        if (window.console) console.warn('[atk-doc] Mermaid 加载失败：', err);
      });
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', boot, { once: true });
  } else {
    boot();
  }
})();
