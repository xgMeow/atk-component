# tools/doxygen

`Doxyfile` 引用的 Doxygen HTML 定制文件，集中放这里：

| 文件 | Doxyfile 选项 | 用途 |
| --- | --- | --- |
| `layout.xml` | `LAYOUT_FILE` | 导航栏 tab 的顺序 / 显隐 / 标题 |
| `header.html` | `HTML_HEADER` | 页头，标题栏区已改写为自有标记 |
| `style.css` | `HTML_EXTRA_STYLESHEET` | 站点皮肤 |
| `nav-row-click.js` | `HTML_EXTRA_FILES` | 左树整行可点（行内空白区点击转发给文字链接） |
| `nav-sync-dock.js` | `HTML_EXTRA_FILES` | 「面板同步」开关从左树挪到导航栏、钉在搜索框左边（悬停/聚焦出说明气泡） |
| `mermaid-lazy.js` | `HTML_EXTRA_FILES` | Mermaid 按需加载：页面里真有 `.mermaid` 才去 CDN 取（替代 Doxygen 默认的模块脚本） |
| `logo.png` | `PROJECT_LOGO` | 标题栏 logo（白字版，取自 atk-doc 的 `logoDark.png`） |

页脚（`HTML_FOOTER`）**没有启用**：目前页脚没有自定义内容，放一个和官方模板一模一样的
文件等于凭空多一个“升级 Doxygen 时要同步”的负担。以后要加访问量统计之类的东西再放。

## 各文件的来源和改动范围

### header.html

由 `doxygen -w html` 生成，改动了三处：

1. **TITLEAREA 区块**：原来 Doxygen 用 `<table> + #projectrow` 排版，这里换成 flex 容器

```html
<div id="titlearea" class="atk-titlearea">
```

标题栏内部全部使用自有类名（`.atk-brand-logo` / `.atk-brand-name` / `.atk-brand-number` /
`.atk-brand-brief` / `.atk-titlearea-search`），所以 `style.css` 里不需要再去覆盖
`#projectrow` / `#projectlogo` / `#projectname` / `#projectalign` 这些 Doxygen 默认类。

`<head>` 里的 `$treeview` / `$search` / `$stylesheet` / `$extrastylesheet` / `$mathjax`
等占位符未动；`PROJECT_NUMBER` 仍嵌在 `PROJECT_NAME` 区块内，与官方模板一致。

2. **`$treeview` 之后加了一段内联脚本**：在 `<head>` 里同步读出 Doxygen 存在
   Cookie / localStorage 里的左右栏宽，写进 CSS 变量 `--atk-nav-width` /
   `--atk-page-width`，供 `style.css` 的「首帧布局」使用（原因见下面
   [首帧布局与 Mermaid](#首帧布局与-mermaid点左树时先撑满再闪出左栏) 一节）。
   必须内联、且必须在 `$treeview` 之后：`Cookie` 由 `cookie.js` 提供，而这段要在
   第一次布局之前跑完。

3. **`$mermaidjs` 占位符换成了 `mermaid-lazy.js`**：Doxygen 1.17.0 输出的 Mermaid
   初始化是 `<script type="module">`，会阻塞 `DOMContentLoaded`（见同一节）。

`</head>` 前另有三个补丁脚本：`nav-row-click.js`（左树整行可点）、
`nav-sync-dock.js`（面板同步开关挪进导航栏）、`mermaid-lazy.js`（Mermaid 按需加载），
见下文各自的小节。

> 改模板注释时注意：**不要在 `header.html` 的注释里写出带 `$` 前缀的占位符**。
> Doxygen 连注释里的占位符也会替换，替换结果落在 `<!DOCTYPE>` 之前会让页面进入怪异模式。
> 需要提到占位符时，像本节这样只在 README 里写。

### layout.xml

由 `doxygen -l` 生成。只改了 `<navindex>`（tab 的显隐 / 标题 / 两个下拉分组）；其余
（class / namespace / file 等页面的段落结构）保持 1.17.0 默认值。

当前文档实际有内容的 tab 是 `简介 / 操作流程（下拉）/ 按功能（下拉）/ 类 / 文件`；
`modules`、`namespaces`、`concepts`、`interfaces`、`structs`、`exceptions`、`examples`
全部标 `visible="no"`——因为 layout.xml 里显式写 `yes` 会让 Doxygen 连**空 tab** 也渲染
出来。以后新增了对应内容再把对应项改回 `yes`。

`简介` tab（`type="mainpage"`）对应 `docs/mainpage.dox` 的 `\mainpage` 标题；左侧树里
这一条显示的是 `\mainpage` 的标题，不是 tab 的 `title`，改名字两处都要动。

`操作流程` tab 不是内置类型，而是 `type="usergroup"`（父项）+ 四个 `type="user"`（子项）：
父项 `url="@ref component_flow"` 指向概览页，子项各指一门语言的操作流程页。顶部鼠标划过出
下拉，左侧树里子项缩进挂在父项下面。`type="pages"` 的 tab 被标成 `visible="no"`——`\page`
页面照常生成，但如果同时开着 pages tab，顶部会多出一个与下拉重复的入口，左侧树也会把四个
语言页平铺成与父项同级。

`按功能` tab 用同一套做法：`topics` tab 标 `visible="no"`（`title` / `intro` 仍要保留，
`topics.html` 的大标题和引导语靠它们），再由 `usergroup url="topics.html"` + 四个 `user`
子项承载——对象 / 工具 / 机动规划 / 可视化，分别指向 `docs/groups.dox` 里的 `\defgroup`，
类的归属靠头文件里的 `\ingroup`。这里 `url` 写相对路径而不是 `@ref`：`topics.html` 是
生成器输出的列表页，没有可引用的标签名（`@ref by_object` 这类只能指到组页）。

**代价**：两个被关掉的 tab 对应的 `pages.html` / 不被引用的列表页仍会生成，但没有入口指向
它们（孤儿页，`pages.html` 的标题还是语言包的「相关页面」）。新增一门语言 = 加一个 `\page`
+ 补一行 `user` tab；新增一个组 = 加 `\defgroup` + 补一行 `user` tab。

**tab 标题**：不写 `title` 时 Doxygen 用语言包默认值，中文界面就是「相关页面」（`pages`，
`Related Pages` 的译名）和「专题」（`topics`，`Topics` 的译名）——与内容无关，容易让人以为
这些页面是「另一些相关页面」或某个具体专题。显式写 `title` 后，顶部 tab、对应列表页的层内
大标题和页面 `<title>` 一起生效（现在是 `简介` / `操作流程` / `按功能`）。`intro` 是
同样的回退规则：留空仍会输出语言包那句「这里列出了所有相关页面:」「这里是所有专题及其简介:」，
所以两处都一并改写成了实际内容。要加外链 tab 用 `<tab type="user" url="…" title="…"/>`，
加下拉分组用 `type="usergroup"`；layout 里 `type` 的取值是固定集合，不能自造。注意窄屏
（768～870px）本来 tab 就挤，加 tab 前先在那个宽度看一眼「面板同步」按钮有没有压到最后一个
tab（见下文 `nav-sync-dock.js` 的已知限制）。

### style.css

写法分两类，改之前先分清楚是哪一类：

1. **标题栏**（`.atk-*`）——结构由 `header.html` 自己写，样式只作用于自有类名。
   只有 `#titlearea` 需要用 `#titlearea.atk-titlearea` 这种 `#id + .类` 的写法，因为
   `doxygen.css` 里的 `#titlearea` 是 ID 选择器，单靠类名压不过它。
2. **菜单栏及其后**（`#main-nav`、`div.header`、`#nav-tree`）——这段 DOM 是 Doxygen
   生成器硬编码输出的，`header.html` 够不到（模板最后一行是 `<!-- end header part -->`，
   之后的 `<div id="main-nav">`、`</div><!-- top -->`、`#side-nav`、`#container` 都由
   C++ 生成器写死），只能覆盖 Doxygen 的默认类。

原先单独放在 `tools/doxy_strip_tags.css` 的规则（隐藏注释里的 作者 / 日期 / 版本 字段）
已并入本文件开头。

文件末尾还藏了页脚的「制作者 … 1.17.0」署名：它由生成器写死在每个页面末尾 `#nav-path`
的 `li.footer` 里，`HTML_FOOTER` 没启用，模板同样够不到，只能按默认类压掉。只藏 `<li>`
会让只含署名的页面（概览 / 类列表 / 文件列表）剩一条 30px 高的空白面包屑条，所以用
`#nav-path:not(:has(li.navelem))` 把整条一并隐藏；类页 / 源码页底部的路径行照旧保留。

### 成员函数汇总表 / 成员函数说明（配色）

这两块的形态（描边、圆角、标签页、卡片）**保持 Doxygen 默认**，只把配色换成中性灰：
默认的 `#D5DDEC` / `#A8B8D9` 描边和 `#F9FAFC` / `#EEF1F7` 底偏蓝，和站点的中性灰不搭。

- 汇总表：单元格描边改 `#e5e8ed`，签名行底色改 `#f8f9fa`，去掉说明行那层内阴影。
  行距、对齐、列宽、分隔全部沿用默认值，打印和扫读时的行对照不受影响。
- 说明区：标签页、签名条、卡片下半部的描边统一 `#e5e8ed`，底色统一 `#f7f8fa`。
  `memtitle` 第一条 `box-shadow` 是用来盖住卡片顶边、把标签页贴到卡片上的，
  它的颜色必须和标签页底色一致（两处都写 `#f7f8fa`），改一处就要同时改另一处。

覆盖规则里只有一条带了 `#doc-content` 前缀：doxygen.css 给汇总表首行补描边的是
`tr.heading + tr[class^='memitem'] td.memItemLeft` 这类 3 个类名的选择器，
其余规则都是同类名、靠书写顺序压过默认值的。升级 Doxygen 后确认
`memberdecls` / `memtitle` / `memproto` / `memdoc` 这些类名还在即可。

### 正文字色与标题色

Doxygen 默认正文是纯黑（`body { color: black }`），和站点其余部分（左树 / 菜单的
`#191919`、`#646a73`）摆在一起偏硬。`style.css` 统一改成 `#213547`（深蓝灰，与 atk-doc
正文同一个值）。

一条 `body` 就够：段落、列表、表格单元格、成员说明区都从 `body` 继承。下面这些是显式
另写的，**不**跟着变，改色时别漏看：

- `.mdescLeft` / `.mdescRight` 用 `#555`：汇总表里的那行说明，刻意压灰当次要信息；
- `pre` / `div.fragment`：代码块，自带语法高亮配色，跟正文色无关；
- 左树 `#191919`、菜单栏 `#646a73` / `#fff`、面包屑 `#354C7B`：属于导航，不是正文。

`.memproto`（成员函数签名条）**必须单独写一条**：`doxygen.css` 给它的是藏青 `#253555`，
不压一下会比正文深一档，所以那里也写 `color: #213547`。

**标题**大多也没有自己的颜色：`.title`（`div.title` 页面大标题）、`h2` / `h3` / `h4.doxsection`
（手写文档的章节）、`h2.memtitle`（成员函数说明的标签页）都是继承 `body` 得到 `#213547` 的。
唯一的例外是 `h2.groupheader`——类页的「Public 成员函数」「详细描述」「成员函数说明」、
目录页的「文件」——`doxygen.css` 给它单独写了藏青 `#354C7B`，`style.css` 里补一条
`h2.groupheader { color: #213547 }` 压掉。同一组规则里还顺带列了 `h1`~`h6`、`.title`、
`div.groupHeader`（后者当前没有被生成出来），作用是换 Doxygen 版本后如果又给某个标题塞了
自己的颜色，能一并盖掉。

升级 Doxygen 后确认 `body` 的 `color` 仍是我们在覆盖的那个默认值（现在是 `#000`），
`.memproto` 仍带自己的 `#253555`，`h2.groupheader` 仍是 `#354C7B`。

### 正文链接色

Doxygen 默认的链接色是藏青 `#3D578C`，在白色正文里偏暗偏灰，和站点主题蓝（左树选中态
`#1456f0`、标题栏渐变、搜索框）不是一家，`style.css` 统一改成 `#235ee1`。

默认色在 `doxygen.css` 里分三处写：`a`、`.contents a:visited`、
`a.el / a.code / a.line`（都带 `:visited` 变体）。正文里绝大多数链接是 `a.el`（指向类 /
成员的那批，全站一万多处），它的两个类名比单条 `a` 更具体，所以三处都得覆盖——只写一条
`a` 只会改掉剩下那一小撮。只改颜色：`a.el` 的粗体、下划线，以及
`span.label a:hover` 那条用 `currentColor` 画的下划线，都跟着新色走，规则本身没动。

右侧索引栏（`#page-nav`）里的条目也是普通 `<a>`，跟着一起变蓝，和左侧树「只有选中项是蓝字」
不一致；想让那栏保持深灰得单独加一条 `#page-nav a { color: … }`，目前按 Doxygen 原样保留。

还有两处不是链接、仍是旧藏青，没有跟着改：

- `#nav-path li.navelem a`（页面底部面包屑）原本就是另一档 `#354C7B`，不属于这次改的
  `#3D578C`；
- `.directory .levels span`（文件浏览页的层级控件）用 `#3D578C`，但它是层级文字不是链接。

升级 Doxygen 后确认 `a` / `.contents a:visited` / `a.el` 这几条默认色还在，否则新版本
可能引入别的高优先级颜色，需要再补一条覆盖。

### Markdown 表格（配色）

`docs/` 里用 `|` 写的表（目前只有首页「按主题查接口」那张）由 Doxygen 渲染成
`table.markdownTable`，默认配色是 Doxygen 自带的藏青：单元格描边 `#2D4068`、表头
`#374F7F` 底 + 白字。整页其余部分是白底 + 中性浅灰，这块深色是页面上唯一的重色，
和白色导航栏、左侧树、成员函数表摆在一起像贴进来的一张别处的图。

`style.css` 里**只换颜色**，形态（1px 网格、表头 110% 字号、单元格内边距、表格外边距）
全部沿用默认：

- 单元格描边 `#2D4068` → `#e5e8ed`（与成员表同一档）；
- 表头底色 `#374F7F` → `#eff2f5`（导航栏下方那条 10px 间隔条的同一色）；
  表头白字 → `#213547`（与正文同色）——浅底上白字没法读，而 110% 粗体本身已经和正文
  拉开了层次，不需要再靠深色块强调。

表头类名按列对齐方式分成 `markdownTableHeadLeft` / `Right` / `Center` / `None` 四个，
默认样式完全一样，覆盖时四个都得列上，漏一个就漏一列。

`\table` 命令输出的是 `table.doxtable`（默认配色与 Markdown 表同一套藏青），目前文档里
没用；哪天真用了，把上面两组选择器里的 `markdownTable` 换成 `doxtable` 即可。

升级 Doxygen 后确认 `doxygen.css` 里仍有 `table.markdownTable` 与四个
`markdownTableHead*` 类名。

### 文档插图（`\image`）

`docs/` 下的页面用 `\image html <文件名> "说明"` 插图，Doxygen 按原始像素输出、不给宽度，
所以 `style.css` 末尾补了 `.image img { max-width: 100%; height: auto; }`，窗口变窄时等比缩小。
图片由 Doxygen **扁平复制**到 HTML 根目录，文件名在整个文档范围内必须唯一，
查找目录由 `Doxyfile` 的 `IMAGE_PATH` 指定。

### nav-row-click.js

Doxygen 生成的左树里，只有条目**文字**是 `<a>`（展开箭头也是另一个独立 `<a>`），
行内其余区域——缩进槽、箭头槽空白、左右内边距——点了没有任何反应。而 `:hover` 是整行
变灰，视觉上等于承诺「这一整行都能点」。这个脚本用事件委托补齐：点在 `<a>` 上直接放行
（文字跳转、箭头展开仍走 navtree.js 的原生逻辑），点在本行其它位置时转发成对文字 `<a>`
的 `.click()`，于是 hash 锚点、`storeLink()` 的树状态记忆、`nolink` 节点的「点一下展开」
全都自动复用，脚本里没有重写导航逻辑。带 Ctrl/Cmd/Shift 点空白区、或中键点，按新标签页打开。

**这类行为只能在生成器输出的 DOM 上加脚本实现，纯 CSS 做不到**（CSS 不能给 `<a>` 扩大
命中区域到整行——即使能用 `::after` 铺满，也会压住相邻的文字链接）。

### nav-sync-dock.js（面板同步开关）

Doxygen 把「面板同步」开关 `#nav-sync` 生成在左树 `#nav-tree-contents` 的最上面，
`position:absolute; top:0; right:0`，正好压在第一条目录上——鼠标扫过去时那个小方块
会盖住条目文字。这个脚本把它挪进**当前可见的那条导航栏**，按搜索框的实测位置定位到
**搜索框左边**：宽屏用 `#main-nav`（渐变蓝标题栏，白图标），窄屏用 `#main-nav-mobile`
（白底收起栏，灰图标），窗口跨过 768px 断点时自动换宿主。

实现上有五点要注意：

1. **坐标写在外层容器 `.atk-nav-sync` 上，不能写 `#nav-sync` 自己**：`navtree.js` 的
   `adjustSyncIconPosition()` 会在每次树数据加载后按滚动条宽度改写
   `#nav-sync.style.right`，写在它身上的坐标会被覆盖。容器是脚本自建的 `<div>`，
   Doxygen 不会碰。
2. **点出去的坐标靠实测**：脚本读 `#MSearchBox` 与宿主导航栏的
   `getBoundingClientRect()` 算 `right`，并在 `load` / `resize` / `document.fonts.ready`
   时重算；量不到（搜索框还没布局）就退回 `style.css` 里的默认值。
3. **层级必须高过菜单容器 `.sm` / `.sm-dox`（z-index:9999）**：那条 `<ul>` 在两条导航栏里
   都铺满整行且是透明底，层级不够高时 `elementFromPoint` 拿到的永远是它——按钮画得再好看，
   鼠标 hover 不进 `:hover`、点击也到不了 `navtree.js` 的监听（宽屏最初给容器写 `z-index:2`，
   就踩了这个坑：看着有按钮，实际完全点不动）。现在统一 `z-index:10000`，`style.css` 里
   有注释说明，别随手调低。
4. **只搬节点、不改行为**：点击切换、`.active` / `.sync` 状态类名仍由 `navtree.js` 管，
   脚本只额外补了键盘可达（`role=button` + Enter / 空格触发原生 click）。按钮外观改成
   36×36 的图标按钮，规则在 `style.css` 末尾的「顶部导航栏 · 面板同步开关」一节。
5. **提示气泡自己画**：`navtree.js` 只在内部 `div.nav-sync-icon` 上留了 `title`
   （`SYNCONMSG` / `SYNCOFFMSG`，即「点击 关闭/开启 面板同步」），原生 tooltip 悬停一秒
   才出，也说不清这块开关管什么；那层图标又被压成透明热区。所以脚本生成
   `.atk-nav-sync__tip`（`role=tooltip`），悬停或键盘聚焦立即出现，文字随状态改写：
   标题「面板同步：开/关」，说明「左侧目录跟随页面滚动 · 点击暂停」/「左侧目录不再跟随
   · 点击恢复」。同时把所有 `title` 摘掉（`MutationObserver` 盯着 `#nav-sync`，挡住
   `navtree.js` 每次重写 innerHTML 时把 title 装回来），无障碍名称改由 `aria-label`
   提供，避免原生气泡和自绘气泡一起弹。气泡的显示状态也靠 `.sync` 类判断，不依赖两个
   脚本的点击监听谁先注册。

升级 Doxygen 后要确认三件事：`#nav-sync` 仍生成在 `#nav-tree-contents` 里、仍由
`navtree.js` 给它加 `.sync` 类、内部图标仍带 `title`（那层现在是透明热区，title 只用来
让脚本摘掉）。这三处任何一个变了，脚本的选择器 / `style.css` 里的状态样式都要跟着改。

已知的布局限制：桌面布局在 768～870px 这一档本来就挤（标题会和中间 tab 重叠），
这 48px（36 图标 + 12 间距）会让按钮压到最后一个 tab 上；更宽（≥1000px）就正常了。

### 首帧布局与 Mermaid（点左树时先撑满再闪出左栏）

**现象**：点左侧树里的任意条目，新页面先按「没有左栏」的样子从窗口最左边铺满正文，
过一会儿（有时是几秒）左树出现、正文整体右移并收窄，看起来就是闪一下。截图里那种
「正文在 x=0、右索引栏跟在正文后面、窗口右边空出一大块」的状态就是这一帧。

**两个原因叠加**：

1. **左栏宽度是脚本写的，不是 CSS 写的。** `style.css` 里没有 `#doc-content` 的
   `margin-left`，`#side-nav` 也没有宽度——这两处都由 `navtree.js` 的 `initResizable()`
   在 `DOMContentLoaded` 时用内联样式写上去。在那之前，`#container` 的两个 `auto`
   轨道按「正文 max-content + 右索引栏」分配，于是正文从 x=0 开始、按内容宽度排版
   （1910px 窗口下实测：正文 1017px、右栏 250px，容器里剩下 640 多 px 空着）。脚本一跑，
   正文 `margin-left` 变成 256px、宽度变成 1404px，整页横向重排。
2. **`DOMContentLoaded` 被 Mermaid 拖住了。** Doxygen 1.17.0 默认客户端渲染 Mermaid，
   输出的是 `<script type="module">` + 从 jsdelivr `import` mermaid。模块脚本会等整条
   依赖链下载、执行完才触发 `DOMContentLoaded`，而 `navtree.js` 正是在
   `DOMContentLoaded` 里建树的。实测（本机，jsdelivr 可达）：直接打开类页面
   `DOMContentLoaded` 1.35s；把 jsdelivr 的每个请求延迟 1.5s 后是 4.26s；把请求直接
   掐断则是 0.51s。也就是说「闪多久」基本等于 mermaid 从 CDN 下载多久。
   更糟的是 1.17.0 会把这段脚本输出到**每个页面**（这是它的已知问题），
   当前文档 1395 个页面一个 Mermaid 图都没有。

**修法**（两处配合，缺一不可）：

- `style.css` 末尾偏前的「首帧布局：先按最终栏宽占位」一节：在 `min-width:768px`
  时直接给 `#doc-content` 写 `margin-left`、给 `#side-nav` 写宽度，并用
  `#container:has(#page-nav)` 把右栏列宽钉成 250px（没有右栏的页面用单列 `auto`）。
  栏宽取 `header.html` 在 `<head>` 里写入的 `--atk-nav-width` / `--atk-page-width`
  （来自 `width` / `pagenav` 两个存储键，默认 250+6 / 250），所以首帧就是最终布局。
  只在 ≥768px 生效：更窄时 `navtree.js` 会按「正文至少 250px」收缩两栏，
  那套算法不在这里复制。
- `mermaid-lazy.js` 取代 `$mermaidjs` 占位符：普通脚本 + 动态 `import`，不阻塞
  `DOMContentLoaded`；页面里没有 `.mermaid` 时连请求都不发。以后真用 `\mermaid`，
  图仍会渲染（比正文晚一点）。

**升级 Doxygen 时**：
- 新模板里不要恢复 `$mermaidjs` 占位符——恢复就等于把阻塞脚本带回 `<head>`，
  闪烁会立刻复现。真要改回官方方案，先把 `MERMAID_RENDER_MODE` 改成 `CLI`
  （构建期渲染，不输出 JS；需要装 mermaid-cli），或者接受代价。
- 保留 `$treeview` 之后那段内联脚本；`initResizable()` 里两栏宽度的算法（分隔条 6px、
  正文最小 250px、栏最小 6px）如果变了，`style.css` 的首帧默认值和 768px 断点要一起看。

### 左树缩进与横向滚动

树的一级缩进 = `.arrow` 的宽度：展开节点是 `padding-left:16*L px + width:16px`，叶子节点是
`width:16*(L+1)px`，两者在每个层级都相等，所以同层文字左沿必须完全对齐。

原生的行内布局下这没问题；但 `.item` 为了箭头垂直居中改成了 flex 容器，`.arrow` 和 `.label`
就成了 flex item，默认 `flex-shrink:1`。栏一窄、类名一长，浏览器就按比例把它们缩掉——
叶子节点没有 padding 撑着，实测能被压到 3.3px，缩进直接归零，同一层的叶子左沿参差不齐
（`IAccessCnstrAngle.h` 落在 19px，而同级的 `IAccessConstraint.h` 还在 94px）。

所以 `style.css` 给 `#nav-tree .item > *` 锁了 `flex-shrink:0`：内容按原宽度溢出，交给
`#nav-tree` 的 `overflow-x:auto` 横向滚动（Doxygen 原生就是这个行为）。改这行之前先确认
横向滚动条还在，否则长类名会被直接裁掉。

## 升级 Doxygen 后要做什么

```bash
# 重新生成官方模板（版本号以实际安装为准）
doxygen -w html header.html footer.html stylesheet.css
doxygen -l layout.xml
```

1. 用新模板替换 `header.html` / `layout.xml`；
2. 把本文档上一节描述的改动**移植**回去（`header.html` 是 TITLEAREA 一块、
   `$treeview` 后的栏宽内联脚本、Mermaid 占位符替换，以及 `</head>` 前三个脚本；
   `layout.xml` 只有 navindex 的 visible）；
3. 重建后检查：菜单栏 tab 是否与原先一致、树栏（`#nav-tree`）能否正常展开、缩进是否
   每级 16px 且窄栏下不塌、搜索框位置是否正常、面板同步开关是否落在搜索框左边、
   `menudata.js` 与改前是否一致；再打开一个类页面并点几次左侧树，确认正文首帧就在
   256px 位置、没有「先撑满再收窄」的过程，且 DevTools 里没有对 jsdelivr 的请求。

模板和 Doxygen 版本是强耦合的——官方默认模板在不同版本间会变（例如 `footer.html` 在
1.11.0 给 `!GENERATE_TREEVIEW` 分支补了一个 `</div><!-- doc-content -->` 闭合标签）。
所以这两份文件开头都留了版本注释，升级时按上面的步骤重新生成再移植，不要直接沿用旧文件。
