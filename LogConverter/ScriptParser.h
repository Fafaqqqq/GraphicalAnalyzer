//
// Created by fafaq on 18.12.2021.
//

#ifndef LOGCONVERTER_SCRIPTPARSER_H
#define LOGCONVERTER_SCRIPTPARSER_H
#include <string>
#include <vector>

class ScriptParser
{
public:
    std::vector<std::pair<std::string, std::string>> Parse(std::ifstream& script_stream);
private:
};


#endif //LOGCONVERTER_SCRIPTPARSER_H
