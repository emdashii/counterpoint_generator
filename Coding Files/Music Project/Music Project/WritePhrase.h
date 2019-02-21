#pragma once
#include "Note.h"

class WritePhrase {
public:
	WritePhrase();
	WritePhrase(char key, int length, int measureLength);
	setSeed();
private:
	writeLowerVoice();
	writeUpperVoice(int speciesType);
	char key;
	int length;
	int timeSignature;
	vector<Note> upperVoice;
	vector<Note> lowerVoice;
	int speciesType;
};
