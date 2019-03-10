#pragma once
#include "Note.h"
#include <vector>

using namespace std;

// TODO complete this class
class Phrase {
public:
	// Constructor
	Phrase(vector<Note*> upperVoice = {}, vector<Note*> lowerVoice = {});

	// Mutators
	void addNoteToUpperVoice(Note* note) { upperVoice.push_back(note); }
	void addNoteToLowerVoice(Note* note) { lowerVoice.push_back(note); }

	// Accessors
	vector<Note*> getUpperVoice() {	return upperVoice; }
	vector<Note*> getLowerVoice() { return lowerVoice; }

private:
	vector<Note*> upperVoice;
	vector<Note*> lowerVoice;
};
