//
// Created by fafaq on 18.12.2021.
//

#include "LogParser.h"

LogParser::LogParser(std::ifstream &&log_stream)
    : logStream(std::move(log_stream)) {}
