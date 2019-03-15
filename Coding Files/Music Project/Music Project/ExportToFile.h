#pragma once
#include "Note.h"
#include "Phrase.h"
#include <string>
#include <vector>

using namespace std;

// NOTE --exported code can be pasted at https://www.hacklily.org/ to see sheet music generate by it
class ExportToFile {
public:
	// Constructor with desired output file info
	ExportToFile(string fileName, string musicTitle, string composer);

	// Add phrase function
	void addPhrase(Phrase* phrase);

	// Final output function, writes all phrases and everything
	void WriteOutput();

private:
	// Private data members
	string fileName;
	string title;
	string composer;
	string key = "";
	string time = "";
	int numVoices;
	// Vector with phrases to be exported
	vector<Phrase*> phrases;

	// Other helper functions
	string convertNoteToOutput(Note note);
	// Function to write the upper and lower voice for one phrase
	void writePhrase(Phrase phrase, int phraseNumber, ofstream &outputFileStream);
	// Check to see if a file exists
	static bool exists(const string& fileName);
};
