#include <iostream>
#include <fstream>
#include <string>
#include "ScriptParser.h"

int main(int argc, char** argv) {

    std::ifstream log_stream(argv[1]);
    std::ifstream scr_stream(argv[2]);
    std::ofstream ga_stream(argv[3]);

    auto m = ScriptParser().Parse(scr_stream);

    for (auto i : m)
    {

    }

    return 0;
}
