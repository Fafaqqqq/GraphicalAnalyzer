//
// Created by fafaq on 18.12.2021.
//

#include "ScriptParser.h"
#include <fstream>

std::vector<std::pair<std::string, std::string>> ScriptParser::Parse(std::ifstream &script_stream)
{
    std::vector<std::pair<std::string, std::string>> parsed_lines;

    while (!script_stream.eof())
    {
        std::string line_for_parse;
        std::getline(script_stream, line_for_parse);

        auto it = line_for_parse.begin();
        for (; it != line_for_parse.end() && *it != '='; it++);
        std::string signal_name;
        std::copy(line_for_parse.begin(), it, std::back_inserter(signal_name));

        std::string log_parser_format;
        std::copy(++it, line_for_parse.end(), std::back_inserter(log_parser_format));

        parsed_lines.push_back(std::make_pair(signal_name,log_parser_format));
    }

    return parsed_lines;
}
