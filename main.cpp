#include <unordered_map>
#include <vector>
#include <iostream>

using Alphabet = std::unordered_map<std::string, std::string>;
using Word = std::vector<std::string>;
// while this is the same type as above, instead of single letters,
// it represents full unicode words
using Sentence = std::vector<std::string>;

/*
 * genAlphabet generates a mapping between names for hebrew
 * characters and their unicode representation.
 */
Alphabet genAlphabet()
{
    Alphabet alph;
   
    alph["alef"] = "\u05D0";
    alph["bet"] = "\u05D1";
    alph["gimel"] = "\u05D2";
    alph["dalet"] = "\u05D3";
    alph["he"] = "\u05D4";
    alph["vav"] = "\u05D5";
    alph["zayin"] = "\u05D6";
    alph["het"] = "\u05D7";
    alph["tet"] = "\u05D8";
    alph["yod"] = "\u05D9";
    alph["final kaf"] = "\u05DA";
    alph["kaf"] = "\u05DB";
    alph["lamed"] = "\u05DC";
    alph["final mem"] = "\u05DD";
    alph["mem"] = "\u05DE";
    alph["final nun"] = "\u05DF";
    alph["nun"] = "\u05E0";
    alph["samekh"] = "\u05E1";
    alph["ayin"] = "\u05E2";
    alph["final pe"] = "\u05E3";
    alph["pe"] = "\u05E4";
    alph["final tsadi"] = "\u05E5";
    alph["tsadi"] = "\u05E6";
    alph["qof"] = "\u05E7";
    alph["resh"] = "\u05E8";
    alph["shin"] = "\u05E9";
    alph["tav"] = "\u05EA";

    return alph;
}

std::string namesToUnicodeWord(Word word, Alphabet alph)
{
    std::string retWord = "";
    for (auto letter: word)
    {
        retWord = alph[letter] + retWord;
    }

    return retWord;
}

int main()
{
    auto a = genAlphabet();
    std::vector<std::string> word{"dalet", "vav", "yod", "dalet"};
    auto unicodeWord = namesToUnicodeWord(word, a);
    std::cout << unicodeWord << std::endl;
}
