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
	vector<int> getNoteOptions() { return noteOptions; }
	
protected:
	vector<int> noteOptions;
	// Now for the species rules.....
	// h = harmonic, m = melodic
	void h_cannotCrossMelody();
	void h_avoidDimFifth();
	void h_noFourthOrSeventh();

	void m_noParallelFifths();
	void m_noSimilarFifths();
	void m_noParallelOctaves();
	void m_noSimilarOctaves();
	void m_noSameNote();
};

