# ConjBrew

ConjBrew is a C++ library for conjugating Hebrew roots.

## Build and Run Instructions

0. make sure you have cmake installed locally
1. `cmake CMakeLists.txt -b build`
2. `cd build`
3. `make`
4. `./conjbrew`

## Example

Below is a code snippet using the library and then its output in a sample.txt file.

```cpp
#include "writer.h"

int main()
{
    std::vector<Word> roots;
    roots.push_back(std::vector<std::string>{"zayin", "kaf", "resh"});
    
    rootsToTxtHomework(roots, Tense::past, "17/02/2020");
}
```

```bash
דיוד 17/02/2020

Root:                         רכז
1st Person Plural             ורכז
1st Person Singular           יתרכז
2nd Person Feminine           תרכז
2nd Person Masculine          תרכז
2nd Person Plural Feminine    תרכז
2nd Person Plural Masculine   םתרכז
3rd Person Feminine           הרכז
3rd Person Masculine          רכז
3rd Person Plural             ורכז
```