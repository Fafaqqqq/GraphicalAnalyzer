//
// Created by fafaq on 18.12.2021.
//

#include "ScriptParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Frame> ScriptParser::Parse(std::istream &script_stream)
{
    std::vector<Frame> parsed_lines;

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


        auto args = std::move(ParseArgs(log_parser_format));
        auto requires = std::move(ParseRequire(log_parser_format));
        parsed_lines.emplace_back(signal_name, std::move(requires), std::move(args));
    }

    return std::move(parsed_lines);
}

std::vector<std::string> ScriptParser::ParseArgs(const std::string &format) {

    std::vector<std::string> args;
    std::istringstream is(format);

    while (!is.eof())
    {
        std::string currentWord;

        is >> currentWord;

        if (currentWord.size() == 2 && currentWord[0] == '%')
        {
            char symbol = currentWord[1];
            if (symbol == 't' || symbol == 'd' || symbol == 's' || symbol == 'c')
            {
                args.emplace_back(currentWord);
            }
        }
    }

    return std::move(args);
}

std::vector<std::string> ScriptParser::ParseRequire(const std::string &format) {

    std::vector<std::string> requires;

    int begin = -1;
    int end = -1;

    for (int i = 0; i < format.size(); ++i)
    {
        if (format[i] == '\"')
        {
            (begin == -1) ? (begin = i) : (end = i);
        }

        if (begin != -1 && end != -1)
        {
            std::string require = format.substr(begin + 1, end - begin - 1);

            requires.emplace_back(require);

            begin = end = -1;
        }
    }

    return std::move(requires);
}


