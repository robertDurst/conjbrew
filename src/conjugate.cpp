/*
 * Robert Durst
 * me at robdurst dot com
 */
#include <iostream>
#include <iomanip>
#include "conjugate.h"

// note that words are in the correct Hebrew order, thus the left-most
// letter is index 0
std::vector<Word> conjugatePresent(Word word)
{
    // singular masculine (sm)
    // _ _ vav _
    Word sm{ word[0], "vav", word[1], word[2] };
    // singular feminine (sf)
    // tav _ _ vav _
    Word sf{ word[0], "vav", word[1], word[2], "tav" };
    // plural masculine (pm)
    // (final mem) yod _ _ vav _
    Word pm{ word[0], "vav", word[1], word[2], "yod", "final mem" };
    // plural feminine (pf)
    //  tav vav _ _ vav _
    Word pf{ word[0], "vav", word[1], word[2], "vav", "tav" };

    std::vector<Word> conjugations { sm, sf, pm, pf };

    return conjugations;
}

std::vector<Word> conjugatePast(Word word)
{
    // ani (a)
    // yod tav _ _ _
    Word a{ word[0], word[1], word[2], "tav", "yod" };

    // atah (atah)
    // tav _ _ _
    Word atah{ word[0], word[1], word[2], "tav" };

    // at (at)
    // tav _ _ _
    Word at{ word[0], word[1], word[2], "tav" };
    
    // who (who)
    // _ _ _
    Word who{ word[0], word[1], word[2] };
    
    // he (he)
    // he _ _ _
    Word he{ word[0], word[1], word[2], "he" };

    // anonchnu (an)
    // vav noon _ _ _
    Word an{ word[0], word[1], word[2], "vav", "noon" };

    // atem (atem)
    // (final mem) tav _ _ _
    Word atem{ word[0], word[1], word[2], "tav", "final mem" };
    
    // aten (aten)
    // (final noon) tav _ _ _
    Word aten{ word[0], word[1], word[2], "tav", "final noon" };
    
    // hem/hen (hh)
    // vav _ _ _
    Word hh{ word[0], word[1], word[2], "vav" };

    std::vector<Word> conjugations{ a, atah, at, who, he, an, atem, aten, hh };

    return conjugations;
}

std::vector<Word> conjugate(Word word, Tense t)
{
    switch(t)
    {
        case Tense::present:
            return conjugatePresent(word);
        case Tense::past:
           return conjugatePast(word);
        default:
           throw std::string("invalid conjugation type received");
    }
}

// helper for pretty printing conjugated lines with labels
void prettyPrint(std::string label, Word word, Alphabet a)
{
    std::cout << std::setw(30) << std::left << label << std::setw(5) << namesToUnicodeWord(word, a) << std::endl;
}

// here it is obvioud that I too tightly couple the conjugation
// return indices with displaying... should be an unordered_map
// in reality... TODO: fix this!
void conjugatePastAndDisplay(Word word)
{
    auto a = genAlphabet();
    auto conjugations = conjugate(word, Tense::past);
    
    prettyPrint("Root: ", word, a);
    prettyPrint("1st Person Singular: ", conjugations[0], a);
    prettyPrint("2nd Person Masculine: ", conjugations[1], a);
    prettyPrint("2nd Person Feminine: ", conjugations[2], a);
    prettyPrint("3rd Person Masculine: ", conjugations[3], a);
    prettyPrint("3rd Person Feminine: ", conjugations[4], a);
    prettyPrint("1st Person Plural: ", conjugations[5], a);
    prettyPrint("2nd Person Plural Masculine: ", conjugations[6], a);
    prettyPrint("2nd Person Plural Masculine: ", conjugations[7], a);
    prettyPrint("3rd Person Plural: ", conjugations[8], a);
}

// TODO: fix for the same reason as above
void conjugatePresentAndDisplay(Word word)
{
    auto a = genAlphabet();
    auto conjugations = conjugate(word, Tense::present);

    prettyPrint("Root: ", word, a);
    prettyPrint("Singular Masculine: ", conjugations[0], a);
    prettyPrint("Singular Feminine: ", conjugations[1], a);
    prettyPrint("Plural Masculine: ", conjugations[2], a);
    prettyPrint("Plural Feminine: ", conjugations[3], a);
}
