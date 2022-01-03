#ifndef LOGCONVERTER_FILTERSCONTEINER_H
#define LOGCONVERTER_FILTERSCONTEINER_H
#include <string>
#include <vector>

class FiltersConteiner
{
public:
    FiltersConteiner() = default;
    explicit FiltersConteiner(const std::string& name);
    FiltersConteiner(const std::string& name,
                     std::vector<std::string>&& requires,
                     std::vector<std::string>&& inputArgs);

    void AddRequire(const std::string& require);
    void AddArg(const std::string& arg);

    std::string GetRequire(int index);
    std::string GetArg(int index);
    std::string Name();

    int GetCountRequires();
    int GetCountArgs();

    ~FiltersConteiner() = default;
private:
    std::string nameSignal;
    std::vector<std::string> requireStrings;
    std::vector<std::string> inputArgList;
};

#endif //LOGCONVERTER_FILTERSCONTEINER_H
