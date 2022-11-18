#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class WordFreqPair
{
    private:
        string word;
        int count;
    public:
        WordFreqPair();
        WordFreqPair(string word, int count);
        void setWord(string setw);
        string getWord();
        void setCount(int setc);
        int getCount();
};

