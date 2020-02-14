/*
 * Robert Durst
 * me at robdurst dot com
 */
#include "conjugate.h"

// note that words are in the correct Hebrew order, thus the left-most
// letter is index 0
std::map<std::string, Word> conjugatePresent(Word word)
{
    std::map<std::string, Word> conjugations;

    // singular masculine (sm)
    // _ _ vav _
    conjugations["Singular Masculine"] = Word{ word[0], "vav", word[1], word[2] };
    // singular feminine (sf)
    // tav _ _ vav _
    conjugations["Singular Feminine"] = Word{ word[0], "vav", word[1], word[2], "tav" };
    // plural masculine (pm)
    // (final mem) yod _ _ vav _
    conjugations["Plural Masculine"] = Word{ word[0], "vav", word[1], word[2], "yod", "final mem" };
    // plural feminine (pf)
    //  tav vav _ _ vav _
    conjugations["Plural Feminine"] = Word{ word[0], "vav", word[1], word[2], "vav", "tav" };

    return conjugations;
}

std::map<std::string, Word> conjugatePast(Word word)
{
    std::map<std::string, Word> conjugations;

    // ani (a)
    // yod tav _ _ _
    conjugations["1st Person Singular"] = Word{ word[0], word[1], word[2], "tav", "yod" };

    // atah (atah)
    // tav _ _ _
    conjugations["2nd Person Masculine"] = Word{ word[0], word[1], word[2], "tav" };

    // at (at)
    // tav _ _ _
    conjugations["2nd Person Feminine"] = Word{ word[0], word[1], word[2], "tav" };
    
    // who (who)
    // _ _ _
    conjugations["3rd Person Masculine"] = Word{ word[0], word[1], word[2] };
    
    // he (he)
    // he _ _ _
    
    conjugations["3rd Person Feminine"] = Word{ word[0], word[1], word[2], "he" };

    // anonchnu (an)
    // vav noon _ _ _
    conjugations["1st Person Plural"] =  Word{ word[0], word[1], word[2], "vav", "noon" };

    // atem (atem)
    // (final mem) tav _ _ _
    conjugations["2nd Person Plural Masculine"] = Word{ word[0], word[1], word[2], "tav", "final mem" };
    
    // aten (aten)
    // (final noon) tav _ _ _
    conjugations["2nd Person Plural Feminine"] = Word{ word[0], word[1], word[2], "tav", "final noon" };
    
    // hem/hen (hh)
    // vav _ _ _
    conjugations["3rd Person Plural"] = Word{ word[0], word[1], word[2], "vav" };

    return conjugations;
}

std::map<std::string, Word> conjugate(Word word, Tense t)
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

