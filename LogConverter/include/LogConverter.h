#ifndef LOGCONVERTER_LOGCONVERTER_H
#define LOGCONVERTER_LOGCONVERTER_H
#include <fstream>
#include <vector>
#include "ScriptParser.h"

class LogConverter
{
public:
    void Convert(const std::string& fromFile,
                 const std::string& toFile,
                 const std::string& filterFile,
                 int count_of_lines);

private:
    std::vector<std::string> ReadLines(std::ifstream& file, int countOfLine);
    std::vector<std::pair<std::string, std::vector<std::string>>> ParseLog(const std::vector<std::string>& inputVec,
                                                                           const std::vector<FiltersConteiner>& filters);
    void CheckFileType(const std::string& fileName, const std::string& expectedType);
};


#endif //LOGCONVERTER_LOGCONVERTER_H
