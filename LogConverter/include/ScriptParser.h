#ifndef LOGCONVERTER_SCRIPTPARSER_H
#define LOGCONVERTER_SCRIPTPARSER_H
#include "FiltersConteiner.h"

class ScriptParser
{
public:
    std::vector<FiltersConteiner> Parse(std::istream& script_stream);

private:
    std::vector<std::string> ParseArgs(const std::string& format);
    std::vector<std::string> ParseRequire(const std::string& format);
};


#endif //LOGCONVERTER_SCRIPTPARSER_H
