#include <iostream>
#include "utils.h"
#include "conjugate.h"

int main()
{
    std::vector<std::string> word{"zayin", "kaf", "resh"};
    conjugatePresentAndDisplay(word);
    conjugatePastAndDisplay(word);
}
