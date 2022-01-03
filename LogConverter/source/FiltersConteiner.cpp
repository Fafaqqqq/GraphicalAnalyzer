#include "../include/FiltersConteiner.h"
#include <stdexcept>

FiltersConteiner::FiltersConteiner(const std::string &name)
        : nameSignal(name) {}

FiltersConteiner::FiltersConteiner(const std::string& name, std::vector<std::string> &&requires, std::vector<std::string> &&inputArgs)
        : nameSignal(name), requireStrings(std::move(requires)), inputArgList(std::move(inputArgs)){}

void FiltersConteiner::AddRequire(const std::string &require)
{
    requireStrings.emplace_back(require);
}

void FiltersConteiner::AddArg(const std::string &arg)
{
    inputArgList.emplace_back(arg);
}

std::string FiltersConteiner::GetRequire(int index)
{

    if (index >= 0 && index < requireStrings.size())
    {
        return requireStrings[index];
    }

    throw std::range_error("Out the range!");
}

std::string FiltersConteiner::GetArg(int index)
{
    if (index >= 0 && index < inputArgList.size())
    {
        return inputArgList[index];
    }

    throw std::range_error("Out the range!");
}

int FiltersConteiner::GetCountRequires()
{
    requireStrings.size();
}

int FiltersConteiner::GetCountArgs()
{
    return inputArgList.size();
}

std::string FiltersConteiner::Name()
{
    return nameSignal;
}
