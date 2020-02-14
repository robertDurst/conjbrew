#pragma once
/*
 * Robert Durst
 * me at robdurst dot com
 *
 * conjugation methods that work through what Rabbi Isaacs calls the "programs"
 * or conjugation patterns
 */
#include <vector>
#include "utils.h"

enum class Tense { present, past };

std::vector<Word> conjugate(Word, Tense);
