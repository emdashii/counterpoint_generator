#pragma once
#include "Note.h"
#include "SpeciesTwo.h"
#include "SpeciesFour.h"
#include "SpeciesOne.h"
#include <vector>
using namespace::std;

// TODO: Complete this class

class WritePhrase {
public:
	WritePhrase(string key, int phraseLength);
	~WritePhrase();
	static void setSeed(int seed);
	int getPhraseLength() const { return phraseLength; }
	int getBeatsPerMeasure() const { return beatsPerMeasure; }
	int getSpeciesType() const { return speciesType; }
	int getTotalLength() const { return phraseLength * beatsPerMeasure; }
	void setBeatsPerMeasure(int beatsPerMeasure) { this->beatsPerMeasure = beatsPerMeasure; }
	void setSpeciesType(int speciesType) { this->speciesType = speciesType; }

	void writeThePhrase();
	void printPhraseI();
	void printPhraseN();

	// These four go together
	Note convertIntToNote(int num);
	int convertScaleDegreeToHalfStep(int halfStep);
	Note convertKeyToNote();
	void setKey(string key) { this->key = key; }

private:
	string key;
	int phraseLength;	// In measures (number of measures)
	int beatsPerMeasure = 4;
	int speciesType = 1;	// Will take a 1, 2, or 4. Need to add a way to use imitative... How about a 0?
	void writeLowerVoice();
	void writeUpperVoice();
	vector<Note> upperVoiceN;
	vector<Note> lowerVoiceN;
	vector<int> upperVoiceI;
	vector<int> lowerVoiceI;
};
