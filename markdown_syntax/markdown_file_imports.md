# [File Imports](https://shd101wyy.github.io/markdown-preview-enhanced/#/file-imports)

## [引用文件的语法](https://shd101wyy.github.io/markdown-preview-enhanced/#/file-imports?id=how-to-use) 

`@import "your_file"`

## [支持引用的文件类型](https://shd101wyy.github.io/markdown-preview-enhanced/#/file-imports?id=supported-file-types)

- 图片(.jpg, .gif, .png, .svg, .bmp, ...)
- .CSV
- .mermaid
- .dot
- .puml
- .html
- .js
- .less, .css
- .pdf
- markdown
- > 其他所有类型的文件都被当作 `code block` 进行处理

## [图片](https://shd101wyy.github.io/markdown-preview-enhanced/#/file-imports?id=configure-images)

**本地图片**
@import "./images/desktop-icon.png" {width="30px" height="30px" title="my title" alt="my alt"}

**网络资源**
@import "https://desktop.github.com/images/desktop-icon.svg" {width="30px" height="30px" title="my title" alt="my alt"}

[**PDF文件**](https://shd101wyy.github.io/markdown-preview-enhanced/#/file-imports?id=import-pdf-file)

**引用指定行**
@import "../README.md" {code_block=true class="line-numbers" line_begin=1 line_end=2}

[**将引用内容看作 Code Chunk**](https://shd101wyy.github.io/markdown-preview-enhanced/#/file-imports?id=import-file-as-code-chunk)