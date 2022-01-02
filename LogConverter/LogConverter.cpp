#include <sstream>
#include <algorithm>
#include <iomanip>
#include "LogConverter.h"

void LogConverter::Convert(const std::string& fromFile, const std::string& toFile, const std::string& filterFile)
{
    std::ifstream log_stream(fromFile);
    std::ifstream scr_stream(filterFile);
    std::ofstream ga_stream(toFile, std::ios::binary);

    auto logs = std::move(ReadFile(log_stream));
    auto filters = std::move(ScriptParser().Parse(scr_stream));
    auto parsed = std::move(ParseLog(logs, filters));

    for (auto frame : filters)
    {
        ga_stream << frame.Name() << ':' << std::endl;

        auto it = std::find_if(parsed.begin(), parsed.end(), [&frame](const std::pair<std::string, std::vector<std::string>>& elem) {
            return frame.Name() == elem.first;
        });

        for (int i = 0; i < it->second.size(); i++)
        {
            ga_stream << '\t' << "frame:\n";
            std::istringstream sin(it->second[i]);

            for (int j = 0; j < frame.GetCountArgs(); j++)
            {
                if (frame.GetArg(j) == "%t")
                {
                    double time;
                    sin >> time;
                    ga_stream << std::setprecision(11) <<"\t\t" << "time: " << time << std::endl;
                }
                else if (frame.GetArg(j) == "%d")
                {
                    int d_value;
                    sin >> d_value;
                    ga_stream << "\t\t" << "value: " << d_value << std::endl;
                }
                else if (frame.GetArg(j) == "%c")
                {
                    char c_value;
                    sin >> c_value;
                    ga_stream << "\t\t" << "value: " << c_value << std::endl;
                }
                else
                {
                    std::string s_value;
                    sin >> s_value;
                }
            }
        }
    }
}

std::vector<std::string> LogConverter::ReadFile(std::ifstream &file) {

    std::vector<std::string> inputLines;

    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);

        inputLines.emplace_back(line);
    }
    return std::move(inputLines);
}

std::vector<std::pair<std::string, std::vector<std::string>>> LogConverter::ParseLog(const std::vector<std::string> &inputVec, const std::vector<Frame>& filters) {

    std::vector<std::pair<std::string, std::vector<std::string>>> filtred;

    for (auto frame : filters)
    {
        auto is_conform = [&frame](const std::string& str) -> bool
        {
            for (int i = 0; i < frame.GetCountRequires(); i++)
            {
                if (str.find(frame.GetRequire(i)) == std::string::npos)
                {
                    return false;
                }
            }

            return true;
        };

        std::vector<std::string> matched;
        std::copy_if(inputVec.begin(), inputVec.end(), std::back_inserter(matched), is_conform);

        for (auto& log : matched)
        {
            for (int i = 0; i < frame.GetCountRequires(); ++i)
            {
                auto req = frame.GetRequire(i);

                log.erase(log.find(req) + 1, req.size() - 1);
            }
        }
        filtred.emplace_back(frame.Name(), std::move(matched));
    }

    return std::move(filtred);
}
