#include "DocSummary.h"
#include "WordFreqPair.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;
vector<WordFreqPair> wordList;

DocSummary::DocSummary(string filename)
{
	numberOfSentences = NULL;
	numberOfWords = NULL;
	fileName;
	wordList;
}
void DocSummary::analyseDocument()
{
	ifstream fileText("input.txt");
	while (fileText >> fileName)
	{
		increaseSentenceCount(fileName);
		numberOfWords++;
		for (int i = 0, length = fileName.size(); i < length; i++)
		{
			if (ispunct(fileName[i]))
			{
				fileName.erase(i--, 1);
				length = fileName.size();
			}
		}
		transform(fileName.begin(), fileName.end(), fileName.begin(), tolower);
		addWord(fileName);
	}
}
void DocSummary::printSummary()
{
	cout << "Total number of sentences: " << numberOfSentences << "\n";
	cout << "Total number of words: " << numberOfWords << "\n";
	for (auto print : wordList)
	{
		cout << print.getWord() << " - " << print.getCount() << "\n";
	}
}
void DocSummary::increaseSentenceCount(string sentence)
{
	for (int i = 0; i < sentence.size(); i++)
	{
		if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!')
		{
			numberOfSentences++;
		}
	}
}
void DocSummary::addWord(string word)
{
	bool findWord = false;
	for (auto &freq: wordList)
	{
		if (word == freq.getWord())
		{
			freq.setCount(freq.getCount() +1);
			findWord = true;
			/*if word is equal to getWord, it will increment by 1, if the next word is not equal to freq.getword
			  and is not the same as as 1st word, it will skip the for loop to below
			*/
		}
	}
	if (findWord == false)
	{
		WordFreqPair wordObj = WordFreqPair(word, 1);
		wordList.push_back(wordObj);
		// if the 2nd word after the first word, 3rd word after the 2nd word,
		// is not the same, it will push it into the object to be looped through
		// and be assigned a frequency count variable in the for loop above. 
	}
	
}
