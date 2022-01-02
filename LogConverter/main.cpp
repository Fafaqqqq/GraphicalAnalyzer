#include <iostream>
#include <fstream>
#include "LogConverter.h"

int main(int argc, char** argv)
{
//    std::ifstream log_stream(argv[1]);
//    std::ifstream scr_stream(argv[2]);
//    std::ofstream ga_stream(argv[3], std::ios::binary);

    LogConverter().Convert(argv[1], argv[3], argv[2]);
    return 0;
}
