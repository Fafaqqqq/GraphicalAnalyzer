#include <sstream>
#include <algorithm>
#include <iomanip>
#include "../include/LogConverter.h"

void LogConverter::Convert(const std::string& fromFile,
                           const std::string& toFile,
                           const std::string& filterFile,
                           int count_of_lines)
{

    CheckFileType(fromFile, "log");
    CheckFileType(toFile, "ga");
    CheckFileType(filterFile, "flt");

    std::ifstream log_stream(fromFile);
    std::ifstream flt_stream(filterFile);
    std::ofstream ga_stream(toFile, std::ios::binary);

    auto filters = std::move(ScriptParser().Parse(flt_stream));


    while (!log_stream.eof())
    {
        auto logs = std::move(ReadLines(log_stream, 10));
        auto parsed = std::move(ParseLog(logs, filters));

        for (auto filter: filters)
        {
            auto it = std::find_if(parsed.begin(), parsed.end(),
                                   [&filter](const std::pair<std::string, std::vector<std::string>> &elem) {
                                       return filter.Name() == elem.first;
                                   });

            if (!it->second.empty())
            {
                ga_stream << filter.Name() << ':' << std::endl;

                for (auto &i: it->second)
                {
                    std::istringstream sin(i);

                    for (int j = 0; j < filter.GetCountArgs(); j++)
                    {
                        if (filter.GetArg(j) == "%t")
                        {
                            double time;
                            sin >> time;
                            ga_stream << std::setprecision(11) << "\t" << "time: " << time << std::endl;
                        }
                        else if (filter.GetArg(j) == "%d")
                        {
                            int d_value;
                            sin >> d_value;
                            ga_stream << "\t\t" << "value: " << d_value << std::endl;
                        }
                        else if (filter.GetArg(j) == "%c")
                        {
                            std::string c_value;
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
    }
}

std::vector<std::string> LogConverter::ReadLines(std::ifstream &file, int countOfLine)
{
    std::vector<std::string> inputLines;

    while (!file.eof() && countOfLine--)
    {
        std::string line;
        std::getline(file, line);

        inputLines.emplace_back(line);
    }
    return inputLines;
}

std::vector<std::pair<std::string, std::vector<std::string>>> LogConverter::ParseLog(const std::vector<std::string> &inputVec,
                                                                                     const std::vector<FiltersConteiner>& filters)
{
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

    return filtred;
}

void LogConverter::CheckFileType(const std::string &fileName, const std::string &expectedType)
{
    auto index = fileName.find(expectedType);

    auto expectedIndex = fileName.size() - expectedType.size();
    if (index != expectedIndex)
    {
        throw std::logic_error("Invalid file format (Expected: ." + expectedType + ")!");
    }
}
