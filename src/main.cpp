#include <iostream>
#include "utils.h"

int main()
{
    auto a = genAlphabet();
    std::vector<std::string> word{"dalet", "vav", "yod", "dalet"};
    auto unicodeWord = namesToUnicodeWord(word, a);
    std::cout << unicodeWord << std::endl;
}
