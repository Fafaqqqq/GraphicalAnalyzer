#include <iostream>
#include <fstream>
#include <sstream>
#include "include/LogConverter.h"

int main(int argc, char** argv)
{
    std::string from;
    std::string to;
    std::string filter;
    std::string str_count_of_lines;
    int count_of_lines = 10;

    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) == "--help" || std::string(argv[i]) == "-h")
        {
            std::cout << "LogConverter [<log_file>] [-f <filter_file>] [-o <output_file>]\n\n";

            std::cout << "Argument description:\n";
            std::cout << "\t <log_file>              path to source file with logs\n";
            std::cout << "\t -f <filter_file>        path to filters file\n";
            std::cout << "\t -o <output_file>        path to source file for GUI\n";
            std::cout << "\t -c <count_of_lines>     count of lines in float window (default = 10)\n";
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
        else if (std::string(argv[i]) == "-c")
        {
            str_count_of_lines = argv[i + 1];
            std::istringstream sin(str_count_of_lines);

            try
            {
                sin >> count_of_lines;
            }
            catch (const std::exception& err)
            {
                std::cerr << err.what() << std::endl;
            }
        }
        else
        {
            from = argv[i];
        }
    }

    LogConverter().Convert(from, to, filter, count_of_lines);
    return 0;
}
