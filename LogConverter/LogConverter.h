//
// Created by fafaq on 18.12.2021.
//

#ifndef LOGCONVERTER_LOGCONVERTER_H
#define LOGCONVERTER_LOGCONVERTER_H
#include <fstream>
#include <vector>
#include "ScriptParser.h"

class LogConverter
{
public:
    std::vector<std::string> Convert(std::vector<std::string>&& arrayToConvert);
};


#endif //LOGCONVERTER_LOGCONVERTER_H
