#include "writer.h"

int main()
{
    std::vector<Word> roots;
    roots.push_back(std::vector<std::string>{"zayin", "kaf", "resh"});
    
    rootsToTxtHomework(roots, Tense::past, "17/02/2020");
}
