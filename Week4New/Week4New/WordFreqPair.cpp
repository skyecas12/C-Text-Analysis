#include "WordFreqPair.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

WordFreqPair::WordFreqPair()
{
	word = nullptr;
	count = 0;
}
WordFreqPair::WordFreqPair(string w, int c)
{
	if (c == NULL)
	{
		count = 1;
	}
	else
		count = c;
	word = w;
}
void WordFreqPair::setWord(string setw)
{
	word = setw;
}
string WordFreqPair::getWord()
{
	return word;
}
void WordFreqPair::setCount(int setc)
{
	count = setc;
}
int WordFreqPair::getCount()
{
	return count;
}