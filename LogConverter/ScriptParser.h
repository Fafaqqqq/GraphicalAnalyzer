//
// Created by fafaq on 18.12.2021.
//

#ifndef LOGCONVERTER_SCRIPTPARSER_H
#define LOGCONVERTER_SCRIPTPARSER_H
#include <string>
#include <vector>

class ScriptParser
{
public:
    class Frame
    {
    public:
        Frame() = default;
        Frame(const std::string& name);
        Frame(const std::string& name,
              std::vector<std::string>&& requires,
              std::vector<std::string>&& inputArgs);

        void AddRequire(const std::string& require);
        void AddArg(const std::string& arg);

        std::string GetRequire(int index);
        std::string GetArg(int index);
        std::string Name();

        int GetCountRequires();
        int GetCountArgs();

        ~Frame() = default;
    private:
        std::string nameSignal;
        std::vector<std::string> requireStrings;
        std::vector<std::string> inputArgList;
    };


    std::vector<Frame> Parse(std::ifstream& script_stream);

private:
    std::vector<std::string> ParseArgs(const std::string& format);
    std::vector<std::string> ParseRequire(const std::string& format);
};


#endif //LOGCONVERTER_SCRIPTPARSER_H
