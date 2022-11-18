#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class DocSummary
{
    private:
        int numberOfWords;
        int numberOfSentences;
        string fileName;
        void increaseSentenceCount(string addSentence);
        void addWord(string addW);
    public:
        DocSummary(string fileName);
        void printSummary();
        void analyseDocument();
};

