#include <iostream>

#include "MagicDict.h"
#include "Utils.h"

using namespace std;

MagicDict::MagicDict(vector<string> words, int maxWordLength) : maxWordLength(maxWordLength)
{
	//Depth array (max word length)
	wordArray = new bool** [maxWordLength - 1];
	for (int i = 0; i < maxWordLength; i++)
	{
		//Parent array (26)
		wordArray[i] = new bool* [LETTERS_IN_ALPHABET];
		for (int j = 0; j < LETTERS_IN_ALPHABET; j++)
		{
			//Child array (26 + 26)  isValidLetter & isWordEnd
			wordArray[i][j] = new bool[LETTERS_IN_ALPHABET];
			for (int k = 0; k < LETTERS_IN_ALPHABET; k++)
			{
				wordArray[i][j][k] = false;
			}
		}
	}

	//Single letter array
	//singleLetterArray = new bool[LETTERS_IN_ALPHABET];
	//for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
	//	singleLetterArray[0] = false;

	for (const string& word : words)
	{
		addWord(word);
	}

	//TODO load words into array
}



bool MagicDict::addWord(string word)
{
	rtrim(word);
	const int wordLength = word.length();

	if (wordLength < 1 || wordLength > maxWordLength)
		return false;

	//All single letters are valid "words"
	if (wordLength == 1)
	{
		//int index = letterToIndex(word[0]);
		//singleLetterArray[index] = true;
		return true;
	}

	for (int i = 0; i < wordLength - 1; i++)
	{
		if (isalpha(word[i]) && isalpha(word[i + 1]))
		{
			int parent = letterToIndex(word[i]);
			int child = letterToIndex(word[i + 1]);

			wordArray[i][parent][child] = true;
		}
	}

	return true;
}

int MagicDict::letterToIndex(char letter)
{
	int offset = 65;
	int index = std::toupper(letter);
	index -= offset;

	//If letter is not a capital letter throw an error
	if (index < 0 || index > 90)
		throw invalid_argument("Non-alpha char passed to MagicDict::letterToIndex!");

	return index;
}



//--Is Valid?--//

bool MagicDict::isValidWord(string word)
{
	rtrim(word);
	const int wordLength = word.length();

	if (wordLength < 1 || wordLength > maxWordLength)
		return false;

	//All single letters are valid "words"
	if (wordLength == 1)
	{
		//int index = letterToIndex(word[0]);
		//return singleLetterArray[index];
		return true;
	}

	for (int i = 0; i < wordLength; i++)
	{
		if (!isValidLetter(i, word[i], word[i + 1]))
			return false;
		if (i == wordLength - 1)
			return isWordEnd(i, word[i], word[i + 1]);
	}

	throw std::runtime_error("An unknown problem has occurred when checking if \"" + word + "\" is spelled correctly.");
}

bool MagicDict::isValidLetter(int depth, char parentLetter, char childLetter)
{
	if (!isalpha(parentLetter) || !isalpha(childLetter))
		return false;

	int parent = letterToIndex(parentLetter);
	int child = letterToIndex(childLetter);

	return wordArray[depth][parent][child];
}

bool MagicDict::isWordEnd(int depth, char parentLetter, char childLetter)
{
	if (!isalpha(parentLetter) || !isalpha(childLetter))
		return false;

	int parent = letterToIndex(parentLetter);
	int child = letterToIndex(childLetter);

	return wordArray[depth][parent][child + 26];
}