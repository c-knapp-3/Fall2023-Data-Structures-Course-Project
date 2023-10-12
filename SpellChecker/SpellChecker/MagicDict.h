#ifndef GIT_GROUP_PROJECT_MAGICDICT_H
#define GIT_GROUP_PROJECT_MAGICDICT_H

#include <string>
#include <vector>
using namespace std;

//Implementation based off of MagicDict as discribed here: https://www.freecodecamp.org/news/finding-the-balance-between-time-and-memory-complexity-an-illustrated-example-4845ab7afadd/
class MagicDict
{
	//--Variables--//
private:
	const static int LETTERS_IN_ALPHABET = 26;

	//bool* singleLetterArray; //All single letters are valid "words"

	///wordArray[depth][parent][child]
	bool*** wordArray;
	int maxWordLength;


	//--Methods--//

public:
	MagicDict(vector<string> words, int maxWordLength);
	bool isValidWord(string word);

	//Returns true if successful. False if word is too long.
	bool addWord(string word);

private:

	/// isValidLetter = wordArray[depth][parent][child]
	bool isValidLetter(int depth, char parentLetter, char childLetter);
	/// isWordEnd = wordArray[depth][parent][child + 26]
	bool isWordEnd(int depth, char parentLetter, char childLetter);

	static int letterToIndex(char letter);

};


#endif //GIT_GROUP_PROJECT_MAGICDICT_H
