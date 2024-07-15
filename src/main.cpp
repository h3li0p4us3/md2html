#include "md2html.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: ./md2html <markdown_file> <html_file>"
              << std::endl;
    return 1;
  }
  std::string MdFile(argv[1]);
  std::string htmlFile(argv[2]);

  if (!md2html(MdFile, htmlFile))
    return 1;
  return 0;
}
