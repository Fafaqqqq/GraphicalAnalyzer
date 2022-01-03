#include <iostream>
#include <fstream>
#include "include/LogConverter.h"

int main(int argc, char** argv)
{
    std::string from;
    std::string to;
    std::string filter;

    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) == "--help" || std::string(argv[i]) == "-h")
        {
            std::cout << "LogConverter [<log_file>] [-f <filter_file>] [-o <output_file>]\n\n";

            std::cout << "Argument description:\n";
            std::cout << "\t <log_file>              path to source file with logs\n";
            std::cout << "\t -f <filter_file>        path to filters file\n";
            std::cout << "\t -o <output_file>        path to source file for GUI\n";
            std::cout << "\t -h [--help]             print this message\n";

            exit(0);
        }
        else if (std::string(argv[i]) == "-f")
        {
            filter = argv[i + 1];
            i++;
        }
        else if (std::string(argv[i]) == "-o")
        {
            to = argv[i + 1];
            i++;
        }
        else
        {
            from = argv[i];
        }
    }
    LogConverter().Convert(from, to, filter);
    return 0;
}
