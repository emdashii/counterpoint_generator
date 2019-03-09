#pragma once
#include "Note.h"
#include "Phrase.h"
#include <string>
#include <vector>

using namespace std;

// TODO: Complete this class
// NOTE -- https://www.hacklily.org/
class ExportToFile {
public:
	// Constructor with desired output file name
	ExportToFile(string fileName, string musicTitle, string composer);
	// Destructor
	~ExportToFile();

	// Add phrase function
	void addPhrase(Phrase phrase);

	// Final output function, writes all phrases and everything
	void WriteOutput();

private:
	// Private data members
	string fileName;
	string title;
	string composer;
	int numVoices;
	// Vector with phrases to be exported
	vector<Phrase*> phrases;

	// Write just the notes for a single phrase
	string convertNoteToOutput(Note note);
	void writePhrase(Phrase phrase, int phraseNumber, ofstream &outputFileStream);

protected:

};
