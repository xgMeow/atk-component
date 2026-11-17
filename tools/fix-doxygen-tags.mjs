#!/usr/bin/env node
/**
 * fix-doxygen-tags.mjs
 *
 * 把 include/ 里沿用 ATK 注释惯例的大写标签（@Author/@Date/@Return/@Param/@Input/@Output）
 * 改写成 Doxygen 能识别的写法，用来消除 .dist/doxygen-warnings.log 里的
 * “warning: Found unknown command '@Xxx'”。
 *
 * 默认只预览，不改任何文件；确认报告后再加 --write。
 * include/ 不在 git 里（.gitignore 屏蔽），所以写入前默认会把原文件备份到
 * .dist/doxygen-tag-fix-backup/<时间戳>/ 下。
 *
 * 用法：
 *   node tools/fix-doxygen-tags.mjs                 # 预览
 *   node tools/fix-doxygen-tags.mjs --write         # 真正修改（先自动备份）
 *   node tools/fix-doxygen-tags.mjs --help
 *
 * 依赖：Node.js >= 18，无第三方包。
 */

import fs from 'node:fs';
import path from 'node:path';
import process from 'node:process';
import { fileURLToPath } from 'node:url';

const SCRIPT_DIR = path.dirname(fileURLToPath(import.meta.url));
const REPO_ROOT = path.resolve(SCRIPT_DIR, '..');

// ---------------------------------------------------------------------------
// 只处理这 6 个标签
// ---------------------------------------------------------------------------
const TAGS = new Set(['author', 'date', 'return', 'param', 'input', 'output']);
/** 视为“空说明”的描述 */
const EMPTY_DESC = new Set(['', '空', '无', '暂无', 'none', 'null', '-', '—', '--']);

const RULE_ORDER = [
  'Author → author',
  'Date → date',
  'Return → return',
  'Return → 删除（目标无返回值）',
  'Return → @note（目标无返回值但有说明）',
  'Return → @note（目标不是函数）',
  'Param → param',
  'Param → param（参数名按类型/前缀对齐）',
  'Param → param（按位置对齐）',
  'Param → param（一行多个参数拆成多行）',
  'Param → @note（参数名对不上声明）',
  'Param → @note（目标不是函数）',
  'Param → 删除（重复的参数说明）',
  'Param → 删除（空标签）',
  'Param → @note（重复且说明不同）',
  'Param → 补齐缺失参数（占位）',
  'Input → 删除（in 分区标记）',
  'Output → 删除（out 分区标记）',
  'Input → @param[in]（带说明的输入）',
  'Output → @param[out]（带说明的输出）',
  'Input → @note（带说明但无法落到参数上）',
  'Output → @note（带说明但无法落到参数上）',
];

// ---------------------------------------------------------------------------
// 命令行参数
// ---------------------------------------------------------------------------
function parseArgs(argv) {
  const opts = {
    write: false,
    includeDir: 'include',
    doxyfile: 'Doxyfile',
    report: path.join('.dist', 'doxygen-tag-fix-report.txt'),
    backupDir: path.join('.dist', 'doxygen-tag-fix-backup'),
    noBackup: false,
    respectExclude: true,
    fillMissing: true,
    verbose: false,
    quiet: false,
  };

  const takesValue = {
    '--include': 'includeDir',
    '--doxyfile': 'doxyfile',
    '--report': 'report',
    '--backup': 'backupDir',
  };

  for (let i = 0; i < argv.length; i++) {
    const a = argv[i];
    if (a === '--write' || a === '-w') opts.write = true;
    else if (a === '--no-backup') opts.noBackup = true;
    else if (a === '--no-exclude') opts.respectExclude = false;
    else if (a === '--fill-missing') opts.fillMissing = true;
    else if (a === '--no-fill-missing') opts.fillMissing = false;
    else if (a === '--verbose' || a === '-v') opts.verbose = true;
    else if (a === '--quiet' || a === '-q') opts.quiet = true;
    else if (a === '--help' || a === '-h') {
      printHelp();
      process.exit(0);
    } else if (takesValue[a]) {
      const v = argv[++i];
      if (v === undefined) fail(`参数 ${a} 缺少取值`);
      opts[takesValue[a]] = v;
    } else if (a.startsWith('--')) {
      fail(`不认识的参数 ${a}，用 --help 查看用法`);
    } else {
      opts.includeDir = a; // 允许直接传目录
    }
  }

  opts.includeDir = path.resolve(REPO_ROOT, opts.includeDir);
  opts.doxyfile = path.resolve(REPO_ROOT, opts.doxyfile);
  opts.report = path.resolve(REPO_ROOT, opts.report);
  opts.backupDir = path.resolve(REPO_ROOT, opts.backupDir);
  return opts;
}

function printHelp() {
  console.log(`fix-doxygen-tags.mjs — 修复 include 里 Doxygen 不认识的大写标签

用法:
  node tools/fix-doxygen-tags.mjs [选项] [目录]

选项:
  -w, --write          真正写入文件（默认只预览，不落盘）
      --include <dir>  要处理的目录，默认 include
      --doxyfile <f>   读取其中的 INPUT/EXCLUDE，默认 Doxyfile
      --report <f>     报告文件，默认 .dist/doxygen-tag-fix-report.txt
      --backup <dir>   写入前的备份根目录，默认 .dist/doxygen-tag-fix-backup/
      --no-backup      不备份（不推荐：include/ 不在 git 里）
      --no-exclude     不理会 Doxyfile 的 EXCLUDE，连被排除的目录一起处理
      --fill-missing   给“只写了部分 @Param”的函数补上缺失参数的 @param 行（默认开启）
      --no-fill-missing 不补缺失参数，只在报告里列出来
  -v, --verbose        逐行打印改动
  -q, --quiet          只打印摘要
  -h, --help           显示本帮助

规则:
  @Author → @author                     原样小写
  @Date   → @date                       原样小写
  @Return → @return                     目标有返回值
          → 删除 / @note                目标是 void、构造函数、析构函数
  @Param  → @param [in] / @param [out]  参数名自动对齐到声明的形参名（同名、忽略大小写、
                                        按类型、补匈牙利前缀、按顺序），实在对不上时
                                        降级成 @note 并写进报告
  @Input  → 删除（分区标记）            后续 @Param 输出成 @param[in]
  @Output → 删除（分区标记）            后续 @Param 输出成 @param[out]

示例:
  node tools/fix-doxygen-tags.mjs
  node tools/fix-doxygen-tags.mjs --verbose --report .dist/report.txt
  node tools/fix-doxygen-tags.mjs --write
`);
}

function fail(msg) {
  console.error(`[错误] ${msg}`);
  process.exit(2);
}

// ---------------------------------------------------------------------------
// Doxyfile：读取 INPUT / EXCLUDE，判断哪些文件真正参与文档生成
// ---------------------------------------------------------------------------
function readDoxyfile(file) {
  const result = { input: [], exclude: [], ok: false };
  let text;
  try {
    text = fs.readFileSync(file, 'utf8');
  } catch {
    return result;
  }
  result.ok = true;
  // 把形如 "KEY = a \\\n  b \\\n  c" 的续行拼起来
  const joined = text.replace(/\r\n/g, '\n').replace(/\\\n/g, ' ');
  for (const rawLine of joined.split('\n')) {
    const line = rawLine.replace(/#.*$/, '').trim();
    if (!line) continue;
    const m = /^([A-Z_]+)\s*=\s*(.*)$/.exec(line);
    if (!m) continue;
    const key = m[1];
    const values = m[2]
      .split(/\s+/)
      .map((s) => s.trim())
      .filter(Boolean);
    if (key === 'INPUT') result.input.push(...values);
    else if (key === 'EXCLUDE') result.exclude.push(...values);
  }
  return result;
}

function toPosix(p) {
  return p.replace(/\\/g, '/');
}

/** 规范化成小写的 posix 相对路径，用于前缀匹配 */
function normalizeDoxyPath(p) {
  return path.posix.normalize(toPosix(p)).replace(/\/+$/, '').toLowerCase();
}

// ---------------------------------------------------------------------------
// 文件遍历
// ---------------------------------------------------------------------------
const SOURCE_EXT = new Set(['.h', '.hpp']);

function walkFiles(dir, excludes, out) {
  let entries;
  try {
    entries = fs.readdirSync(dir, { withFileTypes: true });
  } catch (err) {
    fail(`读不了目录 ${dir}: ${err.message}`);
  }
  for (const ent of entries) {
    const full = path.join(dir, ent.name);
    if (ent.isDirectory()) {
      if (isExcluded(full, excludes)) continue;
      walkFiles(full, excludes, out);
    } else if (ent.isFile()) {
      if (isExcluded(full, excludes)) continue;
      if (SOURCE_EXT.has(path.extname(ent.name).toLowerCase())) out.push(full);
    }
  }
  return out;
}

function isExcluded(full, excludes) {
  if (!excludes.length) return false;
  const rel = normalizeDoxyPath(path.relative(REPO_ROOT, full));
  return excludes.some((ex) => rel === ex || rel.startsWith(ex + '/'));
}

// ---------------------------------------------------------------------------
// 文本行：逐行保留原本的换行符，回写做到最小改动
// ---------------------------------------------------------------------------
function splitLines(text) {
  const lines = [];
  const re = /([^\r\n]*)(\r\n|\n|\r|$)/g;
  let m;
  while ((m = re.exec(text)) !== null) {
    if (m.index === text.length) break;
    lines.push({ text: m[1], eol: m[2] });
    if (m[2] === '') break;
  }
  return lines;
}

function joinLines(lines) {
  let out = '';
  for (const l of lines) out += l.text + l.eol;
  return out;
}

// ---------------------------------------------------------------------------
// 文档注释行扫描：认得 /// 、//! 与 /** ... */
// ---------------------------------------------------------------------------
function scanTagLines(lines) {
  const out = [];
  let inBlockComment = false;
  // 标签名后面可能已经带了方向，如 @param[in] / @param[out]
  const TAG = '@([A-Za-z_][A-Za-z0-9_]*)(\\[[^\\]]*\\])?([\\s\\S]*)';
  for (let i = 0; i < lines.length; i++) {
    const t = lines[i].text;
    let m = null;

    if (inBlockComment) {
      if (/^\s*\*\//.test(t)) {
        inBlockComment = false;
        continue;
      }
      m = new RegExp('^([ \\t]*)(\\*)([ \\t]*)' + TAG + '$').exec(t);
    } else if (/^[ \t]*\/\*\*(?!\/)/.test(t)) {
      if (!t.includes('*/')) inBlockComment = true;
      m = new RegExp('^([ \\t]*)(\\/\\*\\*|\\*)([ \\t]*)' + TAG + '$').exec(t);
    } else {
      m = new RegExp('^([ \\t]*)(\\/\\/\\/|\\/\\/!)([ \\t]*)' + TAG + '$').exec(t);
    }

    if (!m) continue;
    const tagStart = m[1].length + m[2].length + m[3].length + 1; // +1 跳过 '@'
    out.push({
      idx: i,
      prefix: t.slice(0, tagStart),
      tag: m[4],
      dir: m[5] ?? '',
      tagEnd: tagStart + m[4].length + (m[5] ?? '').length,
      rest: m[6],
    });
  }
  return out;
}

/** 相邻的标签行归成一个注释块（同一块共享同一个被注释对象） */
function groupBlocks(tagLines) {
  const blocks = [];
  let cur = null;
  for (const l of tagLines) {
    if (cur && l.idx === cur[cur.length - 1].idx + 1) cur.push(l);
    else {
      cur = [l];
      blocks.push(cur);
    }
  }
  return blocks;
}

// ---------------------------------------------------------------------------
// 找注释块后面真正被注释的声明，解析形参表和返回值
// ---------------------------------------------------------------------------
const KEYWORDS = new Set([
  'const', 'volatile', 'struct', 'class', 'enum', 'union', 'typename',
  'unsigned', 'signed', 'short', 'long', 'int', 'char', 'bool', 'float',
  'double', 'void', 'auto', 'wchar_t', 'char8_t', 'char16_t', 'char32_t',
]);

/** 去掉行尾 // 注释和行内块注释，别把字符串里的 // 当注释 */
function stripLineComment(s) {
  let out = '';
  let quote = null;
  for (let i = 0; i < s.length; i++) {
    const c = s[i];
    if (quote) {
      out += c;
      if (c === '\\') {
        out += s[++i] ?? '';
        continue;
      }
      if (c === quote) quote = null;
      continue;
    }
    if (c === '"' || c === "'") {
      quote = c;
      out += c;
      continue;
    }
    if (c === '/' && s[i + 1] === '/') break;
    if (c === '/' && s[i + 1] === '*') {
      const end = s.indexOf('*/', i + 2);
      if (end === -1) break;
      i = end + 1;
      continue;
    }
    out += c;
  }
  return out;
}

const NONE_TARGET = () => ({ kind: 'none', name: '', params: [], hasReturnValue: false });

/** 从 blockEndIdx 之后找到第一条声明 */
function findTarget(lines, blockEndIdx) {
  let i = blockEndIdx + 1;

  // 跳过空行与普通注释（含 //**** 横幅）；
  // 若中间夹着被注释掉的代码，说明这个注释块文档化的东西已经被注释掉了，
  // 后面的声明并不是它的对象，这时按“没有目标”处理，别乱改参数名。
  let orphan = false;
  while (i < lines.length) {
    const t = lines[i].text.trim();
    if (t === '') {
      i++;
      continue;
    }
    if (t.startsWith('/*') || t.startsWith('*')) {
      i++;
      continue;
    }
    if (t.startsWith('//')) {
      const body = t.replace(/^\/{2,}/, '').trim();
      if (/[;{}]\s*$/.test(body) && !/^[*/=\-_#]+$/.test(body)) orphan = true;
      i++;
      continue;
    }
    break;
  }
  if (orphan) return NONE_TARGET();
  if (i >= lines.length) return NONE_TARGET();

  const first = lines[i].text.trim();
  if (first.startsWith('#')) {
    const m = /^#\s*define\s+([A-Za-z_]\w*)\s*(?:\(([^)]*)\))?/.exec(first);
    if (m) {
      const params = splitTopLevel(m[2] ?? '', ',')
        .map((s) => parseParam(s))
        .filter((p) => p && p.name);
      return { kind: 'macro', name: m[1], params, hasReturnValue: true };
    }
    return NONE_TARGET();
  }

  // 收集声明文本，直到顶层的 ';' 或 '{'
  let acc = '';
  let declarator = null;
  let depthParen = 0;
  let depthBrack = 0;

  for (; i < lines.length; i++) {
    const raw = lines[i].text;
    const trimmed = raw.trim();
    if (trimmed.startsWith('#')) {
      if (acc === '') return NONE_TARGET();
      declarator = acc;
      break;
    }
    const s = stripLineComment(raw);
    let cut = -1;
    for (let k = 0; k < s.length; k++) {
      const c = s[k];
      if (c === '"' || c === "'") {
        const quote = c;
        for (k++; k < s.length; k++) {
          if (s[k] === '\\') k++;
          else if (s[k] === quote) break;
        }
        continue;
      }
      if (c === '(') depthParen++;
      else if (c === ')') depthParen--;
      else if (c === '[') depthBrack++;
      else if (c === ']') depthBrack--;
      else if (depthParen === 0 && depthBrack === 0 && (c === ';' || c === '{')) {
        cut = k;
        break;
      }
    }
    if (cut >= 0) {
      declarator = acc + s.slice(0, cut);
      break;
    }
    acc += s + '\n';
    if (acc.length > 4000) {
      declarator = acc;
      break;
    }
  }

  if (declarator === null) return NONE_TARGET();
  return analyzeDeclarator(declarator);
}

function analyzeDeclarator(decl) {
  const stripped = stripDecorations(decl);

  if (/^(?:class|struct|union|enum|namespace)\b/.test(stripped)) {
    return { kind: 'type', name: '', params: [], hasReturnValue: false };
  }
  if (/^(?:using|typedef)\b/.test(stripped)) {
    return { kind: 'type', name: '', params: [], hasReturnValue: false };
  }

  const groups = topLevelParenGroups(decl).filter((g) => {
    const before = decl.slice(0, g.open).trimEnd();
    // noexcept(...)、throw(...)、__attribute__((...)) 之类不是形参表
    return !/\b(noexcept|throw|decltype|alignas|__attribute__|__declspec|static_assert)$/.test(before);
  });

  let paramGroup = null;
  for (const g of groups) {
    if (isParamListTail(decl.slice(g.close + 1))) paramGroup = g;
  }
  if (!paramGroup) {
    return { kind: 'variable', name: '', params: [], hasReturnValue: false };
  }

  const head = decl.slice(0, paramGroup.open);
  const { name, typeText, isDestructor } = splitDeclaratorHead(head);
  const returnType = normalizeReturnType(typeText);
  const isCtorOrDtor = returnType === '' || isDestructor;
  const hasReturnValue = !isCtorOrDtor && !/^void$/.test(returnType);

  const paramText = decl.slice(paramGroup.open + 1, paramGroup.close);
  const params = splitTopLevel(paramText, ',')
    .map((p) => parseParam(p))
    .filter((p) => p && p.name);

  return { kind: 'function', name, params, hasReturnValue };
}

/** 去掉 template<...>、static/virtual/宏 之类的前缀修饰 */
function stripDecorations(t) {
  let s = t.trim();
  for (let guard = 0; guard < 40; guard++) {
    const before = s;
    s = s.replace(/^template\s*<[\s\S]*?>\s*/, '');
    s = s.replace(
      /^(?:typedef|friend|extern|static|virtual|inline|explicit|constexpr|consteval|constinit|mutable|register|__inline|__forceinline)\b\s*/,
      ''
    );
    s = s.replace(/^\[\[[\s\S]*?\]\]\s*/, '');
    s = s.replace(/^[A-Z][A-Z0-9_]{2,}\b\s*/, ''); // 全大写宏：IATKOBJECT_API / A_NODISCARD
    s = s.replace(/^\s+/, '');
    if (s === before) break;
  }
  return s;
}

function topLevelParenGroups(s) {
  const groups = [];
  let depth = 0;
  let start = -1;
  let quote = null;
  for (let i = 0; i < s.length; i++) {
    const c = s[i];
    if (quote) {
      if (c === '\\') i++;
      else if (c === quote) quote = null;
      continue;
    }
    if (c === '"' || c === "'") {
      quote = c;
      continue;
    }
    if (c === '(') {
      if (depth === 0) start = i;
      depth++;
    } else if (c === ')') {
      depth--;
      if (depth === 0 && start >= 0) {
        groups.push({ open: start, close: i });
        start = -1;
      }
      if (depth < 0) depth = 0;
    }
  }
  return groups;
}

/** 形参表右括号之后只允许限定符和 ';' / '{' */
function isParamListTail(after) {
  let t = after.trim();
  if (/^->/.test(t)) return true; // 尾置返回类型
  t = t.replace(/^=\s*(?:0|default|delete)\b/, '');
  t = t.replace(/^(?:(?:const|volatile|override|final|noexcept|[A-Z][A-Z0-9_]{2,})(?:\s+|$)|&{1,2}\s*)+/, '');
  t = t.trim();
  return t === ';' || t === '{' || t === '';
}

function splitDeclaratorHead(head) {
  let h = head.trim();
  let name = '';
  let isDestructor = false;
  let m;

  if ((m = /(operator\s*(?:\[\]|\(\)|->\*?|[^\s\w])+)\s*$/.exec(h))) {
    name = m[1];
    h = h.slice(0, m.index);
  } else if ((m = /(~?[A-Za-z_]\w*)\s*$/.exec(h))) {
    name = m[1];
    if (name.startsWith('~')) {
      isDestructor = true;
      name = name.slice(1);
    }
    h = h.slice(0, m.index);
  } else {
    return { name: '', typeText: h, isDestructor: false };
  }

  // 类外定义 Foo::Bar(...) 去掉限定
  h = h.replace(/[A-Za-z_]\w*\s*::\s*$/, '');
  return { name, typeText: h, isDestructor };
}

function normalizeReturnType(t) {
  return stripDecorations(t).replace(/\s+/g, ' ').trim();
}

/** 按顶层分隔符切分（忽略括号、模板参数、字符串里的分隔符） */
function splitTopLevel(text, sep) {
  const parts = [];
  let depthParen = 0;
  let depthBrack = 0;
  let depthBrace = 0;
  let depthAngle = 0;
  let quote = null;
  let cur = '';
  for (let i = 0; i < text.length; i++) {
    const c = text[i];
    if (quote) {
      cur += c;
      if (c === '\\') {
        cur += text[++i] ?? '';
        continue;
      }
      if (c === quote) quote = null;
      continue;
    }
    if (c === '"' || c === "'") {
      quote = c;
      cur += c;
      continue;
    }
    if (c === '(') depthParen++;
    else if (c === ')') depthParen = Math.max(0, depthParen - 1);
    else if (c === '[') depthBrack++;
    else if (c === ']') depthBrack = Math.max(0, depthBrack - 1);
    else if (c === '{') depthBrace++;
    else if (c === '}') depthBrace = Math.max(0, depthBrace - 1);
    else if (c === '<') {
      if (/[\w>]/.test(text[i - 1] ?? '')) depthAngle++;
    } else if (c === '>') {
      if (depthAngle > 0) depthAngle--;
    }

    if (c === sep && depthParen === 0 && depthBrack === 0 && depthBrace === 0 && depthAngle === 0) {
      parts.push(cur);
      cur = '';
      continue;
    }
    cur += c;
  }
  parts.push(cur);
  return parts;
}

/** 去掉形参里的默认值（顶层 '=' 之后的部分） */
function stripDefaultValue(s) {
  let depthParen = 0;
  let depthAngle = 0;
  for (let i = 0; i < s.length; i++) {
    const c = s[i];
    if (c === '(') depthParen++;
    else if (c === ')') depthParen--;
    else if (c === '<' && /[\w>]/.test(s[i - 1] ?? '')) depthAngle++;
    else if (c === '>' && depthAngle > 0) depthAngle--;
    else if (c === '=' && depthParen === 0 && depthAngle === 0) {
      const prev = s[i - 1] ?? '';
      const next = s[i + 1] ?? '';
      if (prev !== '=' && next !== '=' && prev !== '!' && prev !== '<' && prev !== '>' && next !== '>') {
        return s.slice(0, i).trim();
      }
    }
  }
  return s.trim();
}

/** 解析单个形参，取出名字和类型 */
function parseParam(raw) {
  if (!raw) return null;
  const s0 = stripDefaultValue(raw);
  if (!s0 || s0 === 'void') return null;

  // 函数指针 / 函数引用：void (*cb)(int)
  const fp = /\(\s*[&*]+\s*([A-Za-z_]\w*)\s*\)/.exec(s0);
  if (fp) {
    const typeText = (s0.slice(0, fp.index) + s0.slice(fp.index + fp[0].length)).trim();
    return { name: fp[1], typeText };
  }

  // 数组后缀会干扰“最后一个标识符”的判断
  const noArray = s0.replace(/\[[^\]]*\]/g, '');
  const ids = [...noArray.matchAll(/[A-Za-z_]\w*/g)];
  if (!ids.length) return { name: null, typeText: s0 };

  const last = ids[ids.length - 1];
  const before = noArray.slice(0, last.index).trim();
  const after = noArray.slice(last.index + last[0].length).trim();
  if (KEYWORDS.has(last[0].toLowerCase()) || !before || /::\s*$/.test(before) || after !== '') {
    return { name: null, typeText: s0 };
  }
  if (!normalizeIdent(before)) return { name: null, typeText: s0 }; // 其实没有类型，是误判
  return { name: last[0], typeText: before };
}

function normalizeIdent(t) {
  return String(t)
    .replace(/\b(const|volatile|struct|class|enum|union|typename|unsigned|signed)\b/g, '')
    .replace(/[\s*&]/g, '')
    .toLowerCase();
}

/** 打印一条声明的可读签名，报告里用 */
function signature(target) {
  if (!target || target.kind === 'none') return '(没有找到被注释的声明)';
  const name = target.name || '(匿名)';
  const params = (target.params ?? [])
    .map((p) => `${p.typeText ?? ''} ${p.name ?? ''}`.trim())
    .join(', ');
  return `${name}(${params})`;
}

/** 把 @Param 后面的那个词对齐到真正的形参名，返回 { name, via } 或 null */
function resolveParamName(token, params, exclude) {
  if (!token || !params.length) return null;
  const t = token.trim();
  const usable = params.filter((p) => p.name && !(exclude && exclude.has(p.name)));
  if (!usable.length) return null;

  const exact = usable.find((p) => p.name === t);
  if (exact) return { name: exact.name, via: 'name' };

  const ci = usable.find((p) => p.name.toLowerCase() === t.toLowerCase());
  if (ci) return { name: ci.name, via: 'name' };

  const nt = normalizeIdent(t);
  if (nt) {
    const byType = usable.filter((p) => normalizeIdent(p.typeText) === nt);
    if (byType.length === 1) return { name: byType[0].name, via: 'type' };
  }

  // 作者常把匈牙利前缀省掉：tangential -> dTangential、classType -> eClassType
  if (t.length >= 3) {
    const lower = t.toLowerCase();
    const bySuffix = usable.filter((p) => {
      const n = p.name.toLowerCase();
      return n !== lower && n.endsWith(lower);
    });
    if (bySuffix.length === 1) return { name: bySuffix[0].name, via: 'suffix' };
    const byPrefix = usable.filter((p) => {
      const n = p.name.toLowerCase();
      return n !== lower && n.startsWith(lower);
    });
    if (byPrefix.length === 1) return { name: byPrefix[0].name, via: 'prefix' };
  }
  return null;
}

// ---------------------------------------------------------------------------
// 注释块改写
// ---------------------------------------------------------------------------
/** 解析 @Param 后面的内容，拆出“参数名”和“说明”；兼容 “& x  说明” 这种写法 */
function parseParamTag(rest) {
  let i = 0;
  while (i < rest.length && (rest[i] === ' ' || rest[i] === '\t')) i++;
  const ws = rest.slice(0, i);
  // 跳过作者手写的 & * const 前缀
  for (;;) {
    const m = /^(?:&|\*+|const\b)/.exec(rest.slice(i));
    if (!m) break;
    i += m[0].length;
    while (i < rest.length && (rest[i] === ' ' || rest[i] === '\t')) i++;
  }
  const m = /^(\S+)/.exec(rest.slice(i));
  if (!m) return { ws, token: '', tail: '', desc: '' };
  const tail = rest.slice(i + m[1].length);
  return { ws, token: m[1], tail, desc: tail.replace(/^[ \t]+/, '').trim() };
}

/** 把一条参数说明拼成 @note 的正文，如 “ 参数 x：说明” */
function noteTail(e) {
  if (!e.token && !e.desc) return '';
  if (!e.desc) return ` 参数 ${e.token}`;
  return ` 参数 ${e.token}：${e.desc}`;
}

/**
 * 改写一个注释块。 * @param lines 整个文件的行
 * @param block 本块的标签行
 * @param target 被注释的声明（findTarget 的结果）
 * @returns {{edits: Array, stats: Object, review: Array, missing: string[], target: Object}}
 *   edits: [{ idx, kind: 'replace'|'delete'|'insertAfter', lines?: string[] }]
 */
function transformBlock(lines, block, target, opts) {
  const edits = [];
  const stats = {};
  const review = [];
  const bump = (rule) => {
    stats[rule] = (stats[rule] ?? 0) + 1;
  };

  const isFuncTarget = target.kind === 'function' || target.kind === 'macro';
  const params = isFuncTarget ? target.params : [];

  // -------------------------------------------------------------------------
  // 第一阶段：先把本块所有 @param 对齐到形参名（包括本来就小写的 @param）
  // -------------------------------------------------------------------------
  const paramEntries = [];
  for (const L of block) {
    if (L.tag.toLowerCase() !== 'param') continue;
    const parsed = parseParamTag(L.rest);
    paramEntries.push({ line: L, ...parsed, name: null, via: null, multi: null });
  }

  if (isFuncTarget) {
    const used = new Set();

    // 1) 同名 / 忽略大小写 / 按类型 / 去匈牙利前缀
    for (const e of paramEntries) {
      if (!e.token) continue;
      const r = resolveParamName(e.token, params, used);
      if (r) {
        e.name = r.name;
        e.via = r.via;
        used.add(r.name);
      }
    }

    // 2) 一行里塞了多个参数名：d11,d12,d13
    for (const e of paramEntries) {
      if (e.name || !e.token.includes(',')) continue;
      const parts = e.token
        .split(',')
        .map((s) => s.trim())
        .filter(Boolean);
      if (parts.length < 2) continue;
      const names = [];
      for (const part of parts) {
        const r = resolveParamName(part, params, new Set([...used, ...names]));
        if (!r) {
          names.length = 0;
          break;
        }
        names.push(r.name);
      }
      if (names.length === parts.length) {
        e.multi = names;
        for (const n of names) used.add(n);
      }
    }

    // 3) 兜底：@param 行数和形参个数一致时，按顺序对齐
    if (paramEntries.length === params.length) {
      for (let i = 0; i < paramEntries.length; i++) {
        const e = paramEntries[i];
        if (e.name || e.multi) continue;
        const p = params[i];
        if (!p || !p.name || used.has(p.name)) continue;
        e.name = p.name;
        e.via = 'position';
        used.add(p.name);
      }
    }
  }

  const documented = new Set();
  for (const e of paramEntries) {
    if (e.name) documented.add(e.name);
    else if (e.multi) for (const n of e.multi) documented.add(n);
  }

  const entryByLine = new Map(paramEntries.map((e) => [e.line.idx, e]));

  // -------------------------------------------------------------------------
  // 第二阶段：逐行生成改写
  // -------------------------------------------------------------------------
  let section = null; // 'in' | 'out' | null
  const seenParams = new Map(); // 形参名 -> 首次出现时的说明（查重用）
  let lastParamPrefix = null;
  let lastParamDirTag = null;

  // 生成 @param / @param[in] / @param[out]：有分区标记时用分区，否则保留行上原有的 [in]/[out]
  const paramTagName = (L) => `param${section ? `[${section}]` : L && L.dir ? L.dir : ''}`;

  for (const L of block) {
    const tagLower = L.tag.toLowerCase();
    if (!TAGS.has(tagLower)) continue;

    const desc = L.rest.replace(/^[ \t]+/, '');
    const descTrim = desc.trim();
    const isCanonical = L.tag === tagLower;
    const lineText = lines[L.idx].text;
    const emptyDesc = descTrim === '' || EMPTY_DESC.has(descTrim.toLowerCase());

    // ---- @Author / @Date ----
    if (tagLower === 'author' || tagLower === 'date') {
      if (isCanonical) continue;
      edits.push({ idx: L.idx, kind: 'replace', lines: [L.prefix + tagLower + L.rest] });
      bump(tagLower === 'author' ? 'Author → author' : 'Date → date');
      continue;
    }

    // ---- @Return ----
    if (tagLower === 'return') {
      if (isCanonical) continue;

      const returnsValue = target.kind === 'macro' || (target.kind === 'function' && target.hasReturnValue);
      if (returnsValue) {
        edits.push({ idx: L.idx, kind: 'replace', lines: [L.prefix + 'return' + L.rest] });
        bump('Return → return');
        continue;
      }

      if (target.kind === 'function') {
        if (emptyDesc) {
          edits.push({ idx: L.idx, kind: 'delete' });
          bump('Return → 删除（目标无返回值）');
        } else {
          edits.push({ idx: L.idx, kind: 'replace', lines: [L.prefix + 'note 返回值：' + descTrim] });
          bump('Return → @note（目标无返回值但有说明）');
          review.push({
            line: L.idx + 1,
            reason: 'return-on-void',
            detail: `目标 ${target.name || '(匿名)'} 没有返回值，原 @Return 说明转成 @note`,
            original: lineText,
          });
        }
        continue;
      }

      // 非函数目标（成员变量 / 类 / 找不到声明）
      if (emptyDesc) {
        edits.push({ idx: L.idx, kind: 'delete' });
        bump('Return → 删除（目标无返回值）');
      } else {
        edits.push({ idx: L.idx, kind: 'replace', lines: [L.prefix + 'note 取值：' + descTrim] });
        bump('Return → @note（目标不是函数）');
        review.push({
          line: L.idx + 1,
          reason: 'return-on-nonfunction',
          detail: `目标不是函数（${target.kind}），原 @Return 说明转成 @note`,
          original: lineText,
        });
      }
      continue;
    }

    // ---- @Input / @Output：分区标记 ----
    if (tagLower === 'input' || tagLower === 'output') {
      section = tagLower === 'input' ? 'in' : 'out';
      const dir = section;
      if (isCanonical) continue;

      if (emptyDesc) {
        edits.push({ idx: L.idx, kind: 'delete' });
        bump(tagLower === 'input' ? 'Input → 删除（in 分区标记）' : 'Output → 删除（out 分区标记）');
        continue;
      }

      // 带说明的分区标记：只有一个形参时正好能落到它头上
      if (isFuncTarget && params.length === 1) {
        edits.push({
          idx: L.idx,
          kind: 'replace',
          lines: [L.prefix + `param[${dir}] ` + params[0].name + ' ' + descTrim],
        });
        bump(tagLower === 'input' ? 'Input → @param[in]（带说明的输入）' : 'Output → @param[out]（带说明的输出）');
        documented.add(params[0].name);
      } else {
        edits.push({ idx: L.idx, kind: 'replace', lines: [L.prefix + `note ${dir === 'in' ? '输入' : '输出'}：` + descTrim] });
        bump(tagLower === 'input' ? 'Input → @note（带说明但无法落到参数上）' : 'Output → @note（带说明但无法落到参数上）');
        review.push({
          line: L.idx + 1,
          reason: tagLower === 'input' ? 'input-with-text' : 'output-with-text',
          detail: `@${L.tag} 带说明但没有可对应的单个形参，转成 @note`,
          original: lineText,
        });
      }
      continue;
    }

    // ---- @Param ----
    if (tagLower === 'param') {
      const e = entryByLine.get(L.idx);
      if (!e) continue;

      lastParamPrefix = L.prefix;
      lastParamDirTag = paramTagName(L);

      // 光秃秃的 “/// @Param”，本来就没写内容，直接删掉
      if (!e.token && !e.desc) {
        edits.push({ idx: L.idx, kind: 'delete' });
        bump('Param → 删除（空标签）');
        continue;
      }

      // 目标不是函数（成员变量 / 类 / 注释掉的原型）：Doxygen 对这类目标照样会
      // 把注释块挂到后面第一个声明上，所以不能留 @param，统一降级成 @note。
      if (!isFuncTarget) {
        edits.push({ idx: L.idx, kind: 'replace', lines: [L.prefix + 'note' + noteTail(e)] });
        bump('Param → @note（目标不是函数）');
        review.push({
          line: L.idx + 1,
          reason: 'param-nonfunction',
          detail: `目标不是函数（${target.kind}），参数 ${e.token} 的说明转成 @note`,
          original: lineText,
        });
        continue;
      }

      // 一行写了多个参数名 → 拆成多行
      if (e.multi) {
        const tag = paramTagName(L);
        const linesOut = e.multi.map((n, i) =>
          i === 0 ? `${L.prefix}${tag}${e.ws}${n}${e.tail}` : `${L.prefix}${tag}${e.ws}${n}`
        );
        edits.push({ idx: L.idx, kind: 'replace', lines: linesOut });
        bump('Param → param（一行多个参数拆成多行）');
        review.push({
          line: L.idx + 1,
          reason: 'param-multi-split',
          detail: `@Param 一行写了多个参数名（${e.multi.join(', ')}），已拆成多行`,
          original: lineText,
        });
        continue;
      }

      if (!e.name) {
        const noteText = e.desc ? ` 参数 ${e.token}：${e.desc}` : ` 参数 ${e.token}`;
        edits.push({ idx: L.idx, kind: 'replace', lines: [L.prefix + 'note' + noteText] });
        bump('Param → @note（参数名对不上声明）');
        review.push({
          line: L.idx + 1,
          reason: 'param-unresolved',
          detail: `参数 ${e.token} 对不上声明 ${signature(target)}，转成 @note`,
          original: lineText,
        });
        continue;
      }

      // 同一个形参被写了两次
      if (seenParams.has(e.name)) {
        if ((seenParams.get(e.name) ?? '') === e.desc) {
          edits.push({ idx: L.idx, kind: 'delete' });
          bump('Param → 删除（重复的参数说明）');
        } else {
          edits.push({
            idx: L.idx,
            kind: 'replace',
            lines: [L.prefix + 'note' + (e.desc ? ` ${e.name}：${e.desc}` : ` ${e.name}`)],
          });
          bump('Param → @note（重复且说明不同）');
        }
        review.push({
          line: L.idx + 1,
          reason: 'param-duplicate',
          detail: `参数 ${e.name} 在本块里重复文档化`,
          original: lineText,
        });
        continue;
      }
      seenParams.set(e.name, e.desc);

      const dirTag = paramTagName(L);
      const needRewrite = !isCanonical || e.name !== e.token || dirTag !== 'param' + L.dir;
      if (needRewrite) {
        edits.push({ idx: L.idx, kind: 'replace', lines: [`${L.prefix}${dirTag}${e.ws}${e.name}${e.tail}`] });
        if (e.via === 'type' || e.via === 'suffix' || e.via === 'prefix') {
          bump('Param → param（参数名按类型/前缀对齐）');
        } else if (e.via === 'position') {
          bump('Param → param（按位置对齐）');
          review.push({
            line: L.idx + 1,
            reason: 'param-by-position',
            detail: `参数 ${e.token} 匹配不到，按顺序对齐成 ${e.name}（${signature(target)}），请确认说明是否对应`,
            original: lineText,
          });
        } else {
          bump('Param → param');
        }
      }
    }
  }

  // -------------------------------------------------------------------------
  // 覆盖率：只写了部分 @Param 的函数，Doxygen 会报“参数未文档化”
  // -------------------------------------------------------------------------
  const missing = [];
  if (target.kind === 'function' && documented.size > 0) {
    for (const p of params) if (!documented.has(p.name)) missing.push(p.name);
  }

  if (missing.length && opts.fillMissing && lastParamPrefix && lastParamDirTag) {
    const missingLines = missing.map((n) => `${lastParamPrefix}param ${n}`);
    const anchor = paramEntries[paramEntries.length - 1].line.idx;
    edits.push({ idx: anchor, kind: 'insertAfter', lines: missingLines });
    bump('Param → 补齐缺失参数（占位）');
  }

  return { edits, stats, review, missing, target, documented };
}

// ---------------------------------------------------------------------------
// 主流程
// ---------------------------------------------------------------------------
function main() {
  const opts = parseArgs(process.argv.slice(2));

  const doxy = readDoxyfile(opts.doxyfile);
  const excludes = opts.respectExclude
    ? doxy.exclude
        .map((p) => path.relative(REPO_ROOT, path.resolve(REPO_ROOT, p)))
        .filter((p) => p && !p.startsWith('..'))
        .map((p) => normalizeDoxyPath(p))
    : [];

  if (!fs.existsSync(opts.includeDir)) fail(`目录不存在：${opts.includeDir}`);
  const files = walkFiles(opts.includeDir, excludes, []).sort();

  const total = { files: files.length, changedFiles: 0, lines: 0 };
  const stats = {};
  const reviewAll = [];
  const missingAll = [];
  const skipped = [];
  const perFile = [];
  const writePlan = [];

  for (const file of files) {
    const rel = toPosix(path.relative(opts.includeDir, file));
    let raw;
    try {
      raw = fs.readFileSync(file);
    } catch (err) {
      skipped.push(`${rel}: 读取失败 ${err.message}`);
      continue;
    }

    let text;
    try {
      text = new TextDecoder('utf-8', { fatal: true, ignoreBOM: true }).decode(raw);
    } catch {
      skipped.push(`${rel}: 不是合法 UTF-8，跳过`);
      continue;
    }

    let hasBom = false;
    if (text.charCodeAt(0) === 0xfeff) {
      hasBom = true;
      text = text.slice(1);
    }

    const lines = splitLines(text);
    const tagLines = scanTagLines(lines);
    if (!tagLines.length) continue;

    const edits = [];
    const fileStats = {};
    const fileReview = [];
    const fileMissing = [];

    for (const block of groupBlocks(tagLines)) {
      const target = findTarget(lines, block[block.length - 1].idx);
      const res = transformBlock(lines, block, target, opts);

      for (const [k, v] of Object.entries(res.stats)) fileStats[k] = (fileStats[k] ?? 0) + v;
      for (const r of res.review) fileReview.push({ ...r, file: rel });
      if (res.missing.length) {
        fileMissing.push({
          file: rel,
          line: block[0].idx + 1,
          target: res.target.name || '(匿名)',
          missing: res.missing,
          documented: [...res.documented],
        });
      }
      edits.push(...res.edits);
    }

    if (!edits.length) continue;

    total.changedFiles++;
    total.lines += edits.length;
    for (const [k, v] of Object.entries(fileStats)) stats[k] = (stats[k] ?? 0) + v;
    reviewAll.push(...fileReview);
    missingAll.push(...fileMissing);
    perFile.push({ rel, count: edits.length, stats: fileStats });

    // 应用改动：按行号倒序，删除/插入都不会打乱尚未处理的行号
    const sorted = [...edits].sort((a, b) => b.idx - a.idx);
    for (const e of sorted) {
      const anchor = lines[e.idx];
      if (!anchor) continue;
      const eol = anchor.eol || '\n';
      if (e.kind === 'delete') {
        lines.splice(e.idx, 1);
      } else if (e.kind === 'insertAfter') {
        const inserted = (e.lines ?? []).map((t) => ({ text: t, eol }));
        lines.splice(e.idx + 1, 0, ...inserted);
      } else {
        const repl = (e.lines ?? []).map((t) => ({ text: t, eol }));
        lines.splice(e.idx, 1, ...repl);
      }
    }

    writePlan.push({
      file,
      rel,
      oldText: (hasBom ? '\uFEFF' : '') + text,
      newText: (hasBom ? '\uFEFF' : '') + joinLines(lines),
    });
  }

  // ---- 写入 ----
  let backupRoot = null;
  if (opts.write && writePlan.length) {
    if (!opts.noBackup) {
      const stamp = new Date()
        .toISOString()
        .replace(/[:T]/g, '-')
        .replace(/\..+$/, '');
      backupRoot = path.join(opts.backupDir, stamp);
      for (const item of writePlan) {
        const dst = path.join(backupRoot, item.rel);
        fs.mkdirSync(path.dirname(dst), { recursive: true });
        fs.writeFileSync(dst, item.oldText);
      }
    }
    for (const item of writePlan) fs.writeFileSync(item.file, item.newText);
  }

  // ---- 报告 ----
  const report = [];
  const push = (s = '') => report.push(s);

  push('Doxygen 注释标签修复报告');
  push(`生成时间: ${new Date().toISOString()}`);
  push(`模式: ${opts.write ? '已写入' : '预览（未写入，加 --write 才落盘）'}`);
  push(`处理目录: ${toPosix(path.relative(REPO_ROOT, opts.includeDir))}`);
  push(
    `Doxyfile: ${doxy.ok ? toPosix(path.relative(REPO_ROOT, opts.doxyfile)) : '未找到，未应用 EXCLUDE'} ` +
      `(INPUT=${doxy.input.join(' ') || '-'}，EXCLUDE=${doxy.exclude.length} 项)`
  );
  push(`备份目录: ${backupRoot ? toPosix(path.relative(REPO_ROOT, backupRoot)) : '（未写入，无备份）'}`);
  push('');
  push(`扫描 .h/.hpp 文件: ${total.files}`);
  push(`含改动的文件: ${total.changedFiles}`);
  push(`改动行数: ${total.lines}`);
  push('');
  push('按规则统计:');
  const extraRules = Object.keys(stats).filter((k) => !RULE_ORDER.includes(k));
  for (const rule of [...RULE_ORDER, ...extraRules]) {
    if (stats[rule]) push(`  ${rule.padEnd(44, ' ')} ${stats[rule]}`);
  }

  if (missingAll.length) {
    push('');
    push(`⚠ 只写了部分 @Param 的函数: ${missingAll.length} 处`);
    push('  转换后 Doxygen 会报 "The following parameter ... is not documented"。');
    push('  加 --fill-missing 可以让脚本自动补 @param 行（不带说明），或手工补齐。');
    for (const m of missingAll.slice(0, 300)) {
      push(
        `  ${m.file}:${m.line}  ${m.target}()  缺: ${m.missing.join(', ')}  已写: ${m.documented.join(', ') || '-'}`
      );
    }
    if (missingAll.length > 300) push(`  ...（其余 ${missingAll.length - 300} 条略）`);
  }

  if (reviewAll.length) {
    push('');
    push(`需人工确认: ${reviewAll.length} 处`);
    const byReason = {};
    for (const r of reviewAll) (byReason[r.reason] ??= []).push(r);
    for (const [reason, items] of Object.entries(byReason)) {
      push(`  [${reason}] ${items.length} 处`);
      for (const it of items.slice(0, 300)) {
        push(`    ${it.file}:${it.line}  ${it.detail}`);
        push(`      ${it.original.trim()}`);
      }
      if (items.length > 300) push(`    ...（其余 ${items.length - 300} 条略）`);
    }
  }

  if (skipped.length) {
    push('');
    push(`跳过的文件: ${skipped.length}`);
    for (const s of skipped) push(`  ${s}`);
  }

  push('');
  push('改动最多的文件:');
  for (const f of [...perFile].sort((a, b) => b.count - a.count).slice(0, 40)) {
    const detail = Object.entries(f.stats)
      .sort((a, b) => b[1] - a[1])
      .map(([k, v]) => `${k}×${v}`)
      .join(', ');
    push(`  ${f.rel}: ${f.count} 行 (${detail})`);
  }

  fs.mkdirSync(path.dirname(opts.report), { recursive: true });
  fs.writeFileSync(opts.report, report.join('\n') + '\n', 'utf8');

  // ---- 控制台 ----
  if (!opts.quiet) {
    console.log(`模式: ${opts.write ? '已写入' : '预览（未写入）'}`);
    console.log(`文件: 扫描 ${total.files}，含改动 ${total.changedFiles}，改动 ${total.lines} 行`);
    for (const rule of [...RULE_ORDER, ...extraRules]) if (stats[rule]) console.log(`  ${rule}: ${stats[rule]}`);
    if (missingAll.length) console.log(`⚠ 只写了部分 @Param 的函数: ${missingAll.length} 处（明细见报告）`);
    if (reviewAll.length) console.log(`需人工确认: ${reviewAll.length} 处（明细见报告）`);
    if (skipped.length) console.log(`跳过: ${skipped.length} 个文件`);
    console.log(`报告: ${toPosix(path.relative(process.cwd(), opts.report))}`);
    if (opts.write) {
      console.log(
        backupRoot ? `备份: ${toPosix(path.relative(process.cwd(), backupRoot))}` : '备份: 未做（--no-backup）'
      );
    } else if (writePlan.length) {
      console.log('提示: 这是预览，确认无误后加 --write 才会修改文件。');
    }
  }

  if (opts.verbose) {
    for (const item of writePlan) {
      console.log(`--- ${item.rel} ---`);
      printLineDiff(item.oldText.replace(/^\uFEFF/, ''), item.newText.replace(/^\uFEFF/, ''));
    }
  }
}

/** 逐行对比，只打印变化的部分（够用即可，不做完整 LCS） */
function printLineDiff(oldText, newText) {
  const a = splitLines(oldText).map((l) => l.text);
  const b = splitLines(newText).map((l) => l.text);
  let i = 0;
  let j = 0;
  while (i < a.length || j < b.length) {
    if (i < a.length && j < b.length && a[i] === b[j]) {
      i++;
      j++;
      continue;
    }
    // 找下一个相同的行，判断是删除还是新增
    let foundA = -1;
    let foundB = -1;
    for (let k = i; k < Math.min(i + 40, a.length); k++) {
      if (b[j] !== undefined && a[k] === b[j]) {
        foundA = k;
        break;
      }
    }
    for (let k = j; k < Math.min(j + 40, b.length); k++) {
      if (a[i] !== undefined && b[k] === a[i]) {
        foundB = k;
        break;
      }
    }
    if (foundA >= 0 && (foundB < 0 || foundA - i <= foundB - j)) {
      for (; i < foundA; i++) console.log(`  - ${a[i]}`);
    } else if (foundB >= 0) {
      for (; j < foundB; j++) console.log(`  + ${b[j]}`);
    } else {
      if (i < a.length) console.log(`  - ${a[i++]}`);
      if (j < b.length) console.log(`  + ${b[j++]}`);
    }
  }
}

main();

