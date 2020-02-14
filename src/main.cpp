#include <iostream>
#include "utils.h"
#include "conjugate.h"
#include "writer.h"

int main()
{
    std::vector<Word> roots;
    
    roots.push_back(std::vector<std::string>{"zayin", "kaf", "resh"});
    roots.push_back(std::vector<std::string>{"gimel", "kaf", "dalet"});
    
    rootsToTxtHomework(roots, Tense::past, "17/02/2020");
}
