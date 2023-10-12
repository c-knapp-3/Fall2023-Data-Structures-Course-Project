#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <vector>

#include "Utils.h"
#include "MagicDict.h"

using namespace std;

int main()
{
	for (int i = 65; i < 65 + 26; i++)
	{
		char letter = i;
		cout << letter;
	}
	cout << "\n";

	string word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < word.length(); i++)
	{
		int letter = word[i];
		cout << letter << " ";
	}
	cout << "\n";



	std::cout << "Hello files!\n";

	//string wordsFile = "/Users/Shared/Test Files/words_alpha.txt"; //Mac
	string wordsFile = "../../Data/words_alpha.txt"; //Windows

	if (!filesystem::exists(wordsFile))
	{
		cout << "File not found.\n";
		return 1;
	}

	fstream file(wordsFile);
	vector<string> words;
	//string rawText = Utils::readAllText(file);
	string line;
	int maxWordLength = 0;
	while (std::getline(file, line, '\n'))
	{
		//cout << line + "\n";
		int lineLength = line.length();
		if (lineLength == 0)
			break;
		words.push_back(line);
		if (lineLength > maxWordLength)
			maxWordLength = lineLength;
	}
	file.close();

	MagicDict MDict(words, maxWordLength);

	string input = " ";
	while (input.length() > 0)
	{
		cout << "Enter a word: ";

		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, input);

		bool isCorrect = MDict.isValidWord(input);
		string ans = isCorrect ? "correctly!\n" : " incorrectly!\n";
		cout << "That word is spelled " << ans;

	}

	return 0;
}
