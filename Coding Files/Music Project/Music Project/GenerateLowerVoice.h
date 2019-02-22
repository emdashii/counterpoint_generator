#pragma once
#include "Note.h"
#include <vector>
using namespace::std;

class GenerateLowerVoice
{
public:
	GenerateLowerVoice();
	~GenerateLowerVoice();
	vector<Note> getLowerVoice() { return lowerVoice; }
private:
	vector<Note> lowerVoice();
};

