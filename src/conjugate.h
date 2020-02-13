/*
 * Robert Durst
 * me at robdurst dot com
 *
 * conjugation methods that work through what Rabbi Isaacs calls the "programs"
 * or conjugation patterns along with methods that pretty print/display results.
 */
#include <vector>
#include "utils.h"

enum class Tense { present, past };

std::vector<Word> conjugate(Word, Tense);

// a few wrapper methods that deal with nice formatting and display
void conjugatePastAndDisplay(Word);
void conjugatePresentAndDisplay(Word);
