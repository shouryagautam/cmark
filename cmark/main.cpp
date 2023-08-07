//Finally, we write the main function of our markdown parser for testing.

//Create and save `main.cpp` in `/home/labex/Code/`, and write the following code.

//```cpp
//
//  main.cpp
//  MarkdownParser
//

#include <fstream>          // std::ofstream
#include "mdtransform.hpp"  // Markdown parser class

int main() {
    // construct markdown parser object
    MarkdownTransform transformer("test.md");
    
    // getTableOfContents will be used retrieve TOC of markdown file
    std::string table = transformer.getTableOfContents();
    
    // fetch HTML content of Markdown file
    std::string contents = transformer.getContents();
    
    // head information of HTML file
    std::string head = "<!DOCTYPE html><html><head>\
        <meta charset=\"utf-8\">\
        <title>Markdown</title>\
        <link rel=\"stylesheet\" href=\"github.markdown.css\">\
        </head><body><article class=\"markdown-body\">";
    std::string end = "</article></body></html>";
    
    // write to file
    std::ofstream out;
    out.open("output/index.html");
    // put HTML contents inside of <article></article>
    out << head+table+contents+end;
    out.close();
    return 0;
}