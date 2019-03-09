#pragma once
#include "Note.h"
#include <vector>

using namespace std;

// TODO complete this class
class Phrase {
public:
	Phrase();
	~Phrase();

	vector<Note*> getUpperVoice() {	return upperVoice; }
	vector<Note*> getLowerVoice() { return lowerVoice; }

private:
	vector<Note*> upperVoice;
	vector<Note*> lowerVoice;
};
