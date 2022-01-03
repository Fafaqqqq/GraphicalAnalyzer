#include <iostream>
#include <fstream>
#include "include/LogConverter.h"

int main(int argc, char** argv)
{
    if (argc == 1 || argc == 2 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h"))
    {
        std::cout << "help topic\n";
    }

    //LogConverter().Convert(argv[1], argv[3], argv[2]);
    return 0;
}
