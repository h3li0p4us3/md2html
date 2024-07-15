/*
TODOs:
1.Fix icon Links.
2. add support for code blocks
*/

#pragma once
#include <cstring>
#include <fstream>
#include <iostream>
#include <regex>

bool md2html(const std::string& input_path, const std::string& output_path) {
    std::ifstream inputFile(input_path);
    std::ofstream outputFile(output_path);

    if (!inputFile.is_open()) {
        std::cerr << "Error Opening input file" << std::endl;
        return false;
    }

    std::string line;
    std::vector<std::string> html_lines; // the converted output for saving in html format.

    while (std::getline(inputFile, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());

        if (line.find_first_of("#") == 0) {
            int header_lvl = line.find_first_not_of("##");
            std::string line_content = line.substr(header_lvl + 1);
            html_lines.push_back("<h" + std::to_string(header_lvl + 1) + ">" +
                line_content + "</h" +
                std::to_string(header_lvl + 1) + ">");
        }
        else {
            std::regex md_formatting(
                "\\*(.*?)\\*|__(.*?)__|\\*(.*?)\\*|_(.*?)_"
            );
            std::smatch matches;
            std::string replacement;

            if (std::regex_search(line, matches, md_formatting)) {
                replacement =
                    matches.str(1).empty() ? "<strong>" + matches.str(2) + "</strong>"
                    : matches.str(3).empty() ? "<strong>" + matches.str(4) + "</strong>"
                    : matches.str(5).empty() ? "<em>" + matches.str(6) + "</em>"
                    : "<em>" + matches.str(7) + "</em>";
                line = replacement;
            }


            // Convert Icons(Images)
            std::regex icons("\\!\\[(.*?)\\]\\((.*?)\\)");
            if (std::regex_search(line, matches, icons)) {
                replacement = "<img src=\"" + matches.str(2) + "\">";
                line = replacement;
            }
            // Convert Links
            std::regex link("\\[(.*?)\\]\\((.*?)\\)");
            if (std::regex_search(line, matches, link)) {
                replacement =
                    "<a href=\"" + matches.str(2) + "\">" + matches.str(1) + "</a>";
                line = replacement;
            }


            if (line.find("- ") == 0) {
                html_lines.push_back("<li>" + line.substr(2) + "</li>");
            }
            else if (std::regex_match(line, std::regex("^\\d+\\."))) {
                html_lines.push_back("<li>" + line.substr(1) + "</li>");
            }
            else {
                html_lines.push_back("<p>" + line + "</p>");
            }
        }
    }
    inputFile.close();
    std::string html_content = "\n";
    for (const auto& line : html_lines) {
        html_content += line + "\n";
    }
    std::string html_template = R"(
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>md2html</title>
        </head>
        <body>

            %HTML_CONTENT%

        </body>
        </html>
    )";

    size_t rpc = html_template.find("%HTML_CONTENT");
    html_template.replace(rpc, strlen("%HTML_CONTENT%"), html_content);
    outputFile << html_template;

    if (!outputFile.is_open()) {
        std::cerr << "Error opening output File." << std::endl;
        return false;
    }
    else {
        outputFile.close();
        std::cout << "Coversion complete: " << output_path << std::endl;
        return true;
    }
}