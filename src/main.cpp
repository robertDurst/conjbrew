#include "writer.h"

int main()
{
    std::vector<Word> roots;
    roots.push_back(std::vector<std::string>{"bet", "dalet", "qof"});
    roots.push_back(std::vector<std::string>{"kaf", "tav", "bet"});
    roots.push_back(std::vector<std::string>{"gimel", "mem", "resh"});
    roots.push_back(std::vector<std::string>{"mem", "kaf", "resh"});
    roots.push_back(std::vector<std::string>{"kaf", "gimel", "shin"});
    roots.push_back(std::vector<std::string>{"zayin", "kaf", "resh"});
    roots.push_back(std::vector<std::string>{"shin", "mem", "resh"});
    roots.push_back(std::vector<std::string>{"resh", "qof", "dalet"});
    roots.push_back(std::vector<std::string>{"samekh", "gimel", "resh"});
    roots.push_back(std::vector<std::string>{"qof", "lamed", "tav"});
    
    rootsToTxtHomework(roots, Tense::past, "17/02/2020");
}
