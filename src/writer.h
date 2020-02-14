#pragma once
/*
 * Robert Durst
 * me at robdurst dot com
 *
 * included are methods for outputting conjugations in various
 * ways i.e. writing to a txt file for printing conjugations for
 * homework.
 */
#include <vector>
#include "conjugate.h"
#include "utils.h"

void rootsToTxtHomework(std::vector<Word>, Tense, std::string);