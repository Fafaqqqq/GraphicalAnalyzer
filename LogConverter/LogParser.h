//
// Created by fafaq on 18.12.2021.
//

#ifndef LOGCONVERTER_LOGPARSER_H
#define LOGCONVERTER_LOGPARSER_H
#include <fstream>
#include <vector>

class LogParser
{
public:
    LogParser() = delete;
    explicit LogParser(std::ifstream&& log_stream);


private:
    std::ifstream logStream;
};


#endif //LOGCONVERTER_LOGPARSER_H
