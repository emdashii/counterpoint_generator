#pragma once
#include "Note.h"
#include <vector>
using namespace::std;

class GenerateLowerVoice : Note
{
public:
	GenerateLowerVoice(int length = 8);
	~GenerateLowerVoice();
	int pickRandomInterval();
	vector<int> getLowerVoice() { return lowerVoice; }
	void printLowerVoice();
	
private:
	vector<int> lowerVoice;
	int length;
};

