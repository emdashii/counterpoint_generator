#pragma once
#include "Note.h"
#include "Species.h"
#include <vector>
using namespace::std;

// TODO: Complete this class -- Elliott

class SpeciesOne : public Species
{
public:
	SpeciesOne();
	//SpeciesOne(Note noteBefore, Note noteBelow, Note beforeAndBelow);
	~SpeciesOne();
	int chooseNextNote();

	// These four functions go together. 
	void writeImitativeTwoVoices(int length = 8);	// Uses writeLower
	vector<int> writeImitativeLowerVoice(int length); // Uses Up and Down
	int pickImitativeUp();
	int pickImitativeDown();
	void printImitativeCounterpoint(vector<int> upper, vector<int> lower);
	/*
protected:
	// Now for the species rules.....
	bool melodicRule1a();
	bool melodicRule1b();
	bool harmonicRule1a();
	bool harmonicRule1b();
	*/
};

