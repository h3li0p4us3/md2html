# md2html

## a tool for converting markdown files to HTML

### About

md2html is a easy-to-use command-line tool designed to convert Markdown (.md) files into HTML (.html) format. It's a side project i did to learn regex in C++

### Features

- **Simple Usage**: All you need is your input markdown file.
- **Cross-platform Compatibility**: you can build it and use it across Windows, Linux, and maybe macOS.

### Prerequisites

Ensure you have CMake installed on your system. If not, please visit [CMake's official website](https://cmake.org/download/) for installation instructions.

### Build

Follow these steps to compile md2html:

```bash
cd Build
cmake ..
make
```

### Usage

To convert a Markdown file to HTML, run the following command in your terminal:

```bash
./md2html input.md output.html
```

Replace `input.md` with the path to your Markdown file, `output.html` with the desired output HTML file name.

### Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for discussion.

### License

This project is licensed under the GPL-2.0 license. See the [LICENSE](LICENSE) file for details.
