#pragma once
#include "Note.h"
#include <vector>
#include "Species.h"
using namespace::std;

class GenerateLowerVoice : public Species {
public:
	GenerateLowerVoice(int length = 8);
	int pickRandomInterval();
	vector<int> getLowerVoice() { return lowerVoice; }
	void printLowerVoice();

	int chooseNextNote();

private:
	vector<int> lowerVoice;
	int length;
};
