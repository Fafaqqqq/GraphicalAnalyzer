#ifndef LOGCONVERTER_LOGCONVERTER_H
#define LOGCONVERTER_LOGCONVERTER_H
#include <fstream>
#include <vector>
#include "ScriptParser.h"

class LogConverter
{
public:
    void Convert(const std::string& fromFile, const std::string& toFile, const std::string& filterFile);

    std::vector<std::string> ReadFile(std::ifstream& file);
    std::vector<std::pair<std::string, std::vector<std::string>>> ParseLog(const std::vector<std::string>& inputVec, const std::vector<FiltersConteiner>& filters);
};


#endif //LOGCONVERTER_LOGCONVERTER_H
