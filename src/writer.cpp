/*
 * Robert Durst
 * me at robdurst dot com
 */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include "writer.h"

// helper for pretty printing conjugated lines with labels
void prettyDisplay(std::string label, Word word, Alphabet a, std::shared_ptr<std::fstream> file)
{
    *file << std::setw(30) << std::left << label << std::setw(5) << namesToUnicodeWord(word, a) << std::endl;
}

// helper for newlines
void writeNewline(std::shared_ptr<std::fstream> file)
{
    *file << std::endl;
}

// helper for a header
void writeHeader(std::string header, std::shared_ptr<std::fstream> file)
{
    *file << std::left << header << std::endl;
    *file << std::endl;
}

std::fstream openFile(std::string filename)
{
    std::fstream file;
    file.open(filename, std::ios::out);
    if(!file)
    {
        std::cout<<"Error in creating file!!!"<<std::endl;
        // TODO: deal with this error
    }

    return file;
}

void conjugatePastAndDisplay(Word word, std::shared_ptr<std::fstream> file)
{
    auto a = genAlphabet();
    auto conjugations = conjugate(word, Tense::past);

    prettyDisplay("Root: ", word, a, file);

    for (auto conjugation: conjugations)
    {
        prettyDisplay(conjugation.first, conjugation.second, a, file);
    }
}

void conjugatePresentAndDisplay(Word word, std::shared_ptr<std::fstream> file)
{
    auto a = genAlphabet();
    auto conjugations = conjugate(word, Tense::present);

    prettyDisplay("Root: ", word, a, file);
    
    for (auto conjugation: conjugations)
    {
        prettyDisplay(conjugation.first, conjugation.second, a, file);
    }
}

void rootsToTxtHomework(std::vector<Word> roots, Tense t, std::string date)
{
    auto file = std::make_shared<std::fstream>(openFile("sample.txt"));

    auto myName = std::vector<std::string>{"dalet", "vav", "yod", "dalet"};
    auto a = genAlphabet();
    writeHeader(namesToUnicodeWord(myName, a) + " " + date, file);

    switch (t)
    {
        case Tense::present:
            for (auto root: roots)
            {
                conjugatePresentAndDisplay(root, file);
                writeNewline(file);
            }
            return;
        case Tense::past:
            for (auto root: roots)
            {
                conjugatePastAndDisplay(root, file);
                writeNewline(file);
            }
            return;
        default:
            return;
    }
}