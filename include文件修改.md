## 第一层：消掉原有告警（8572 行改动）

根因只有一个：**Doxygen 的命令名区分大小写**，这 6 个大写标签它一个都不认。

| 原写法               | 处理                                                         | 数量            |
| -------------------- | ------------------------------------------------------------ | --------------- |
| `@Author` / `@Date`  | 直接改小写                                                   | 2098 / 2098     |
| `@Return`            | 有返回值→`@return`；void/构造/析构→删除或转 `@note`          | 1282 / 804 / 12 |
| `@Param`             | 对齐到真实形参名→`@param`（可带 `[in]/[out]`）               | 1132            |
| `@Input` / `@Output` | 本就不是 doxygen 命令，当“分区标记”删掉，语义转成参数的 `[in]/[out]` | 971 / 18        |

约 972 行是**纯语义保留**而非删信息：`@Input` 段落后面的参数会变成 `@param[in]`，`@Output` 后面的变成 `@param[out]`——原来那份“哪些是入参、哪些是出参”的信息没丢。

## 第二层：不引入新告警（这才是脚本的核心难点）

我拿 doxygen 1.17 实测过，简单替换会冒出这几类新告警，脚本分别做了处理：

1. **`@Return` 写在 void / 构造 / 析构函数上** → `found documented return type ... that does not return anything`。这类函数在这仓库里几乎每个都有 `@Return 空`，直接转换会新增几百条。脚本解析声明判断返回类型后，空说明的直接删行，有内容的转 `@note 返回值：…`（8 处）。
2. **`@Param` 后面写的不是参数名** → `argument 'x' of command @param is not found in the argument list`。实际有四种写法：写类型（`@Param EVeProfile 姿态类型`、`@Param IAtkObject*`）、省匈牙利前缀（`@Param tangential` ↔ `dTangential`）、带引用符号（`@Param & x`）、一行多个（`@Param d11,d12,d13`）。脚本按「同名 → 忽略大小写 → 按类型 → 补前后缀 → 数量一致时按顺序」逐级对齐，共处理 122 行；剩下 7 行真对不上的降级成 `@note 参数 …`，信息不丢、也不报错。
3. **函数只写了一部分参数** → `The following parameter ... is not documented`（`WARN_IF_INCOMPLETE_DOC=YES` 会报，注意这跟 `WARN_NO_PARAMDOC=NO` 不冲突）。默认给缺的参数补一行不带说明的 `@param xxx`。
4. **重复 `@param` / 空标签** → 同名的第二条转 note 或删，光秃秃的 `/// @Param`（20 行）直接删。
5. **注释块挂错函数** → 有 4 个文件的注释块文档化的是**已被注释掉的原型**（如 `//bool OutputJ2000Report(...)`），doxygen 会把这块注释算到后面第一个真实声明头上，既报 `argument not found` 又报 `too many @param commands`。脚本识别出“中间夹着被注释掉的代码”就按“无目标”处理，不再乱改参数名。

净效果：在我复制的整份 `include` 上，unknown command 从 8463 → **0**，且**没有新增任何 `@param`/`@return` 类告警**。

## 第三层：让改动本身可控（这层是工程约束，不是 doxygen 问题）

因为 `/include/` 在 `.gitignore` 里，改错了没有 git 能回滚，所以：

- 默认 **dry-run**，必须显式 `--write` 才落盘；
- `--write` 前自动备份原文件到 `.dist/doxygen-tag-fix-backup/<时间戳>/`，保持目录结构，拷回去即还原；
- **幂等**：连跑两次，第二次 0 改动；
- **最小改动**：只动那 6 类标签行的标签名/参数名，保留每行原有缩进、Tab、BOM、CRLF/LF（这几种全验证过）；
- 尊重 Doxyfile 的 `EXCLUDE`，只处理真正参与文档生成的 424 个文件，不碰 `Ast*` 那些外部头文件；
- 产出可复查报告 [.dist/doxygen-tag-fix-report.txt](.dist/doxygen-tag-fix-report.txt)：按规则统计 + 逐文件明细 + 69 处「需人工确认」（其中 36 处是按顺序硬对的参数名，值得你扫一眼）。

**它没解决、也解决不了的**：`AsTCatRes` 缺注释块（[include/CAT/ICat.h:17](include/CAT/ICat.h#L17)）和 `DOT_GRAPH_MAX_NODES=50` 太小导致的 `IClassInfo` 继承图告警——这两条一条要补注释、一条要改 Doxyfile，都不该由批量脚本代劳。