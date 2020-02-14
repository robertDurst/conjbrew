#pragma once
/*
 * Robert Durst
 * me at robdurst dot com
 *
 * basic utility methods for creation, transformation, and
 * translation of Hebrew character unicode and names.
 */
#include <unordered_map>
#include <vector>

using Alphabet = std::unordered_map<std::string, std::string>;
using Word = std::vector<std::string>;
// while this is the same type as above, instead of single letters,
// it represents full unicode words
using Sentence = std::vector<std::string>;

// genAlphabet generates a mapping between names for hebrew
// characters and their unicode representation.
Alphabet genAlphabet();

// namesToUnicodeWord takes a list of character names and
// converts it to a string of unicodes.
std::string namesToUnicodeWord(Word, Alphabet);
