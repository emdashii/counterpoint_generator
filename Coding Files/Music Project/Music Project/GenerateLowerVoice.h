#pragma once
#include "Note.h"
#include <vector>
using namespace::std;

class GenerateLowerVoice
{
public:
	GenerateLowerVoice();
	GenerateLowerVoice(Note key = Note_C1, int length = 8);
	~GenerateLowerVoice();
	int pickRandomInterval();
	Note convertIntervalToKey(Note noteBefore, int interval);
	vector<Note> getLowerVoice() { return lowerVoice; }
private:
	vector<Note> lowerVoice();
	Note key;
	int length;
};

