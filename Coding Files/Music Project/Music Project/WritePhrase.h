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
	WritePhrase(int measureLength, int beatsPerMeasure, int speciesType);
	~WritePhrase();
	static void setSeed();
	int getMeasureLength() { return measureLength; }
	int getBeatsPerMeasure() { return beatsPerMeasure; }
	int getSpeciesType() { return speciesType; }
	int getTotalLength() { return measureLength * beatsPerMeasure; }

	// from Export to file - moved here
	Note convertIntToNote(int num);
	int convertScaleDegreeToHalfStep(int halfStep);
	Note convertKeyToNote();
	void setKey(string key) { this->key = key; }

private:
	string key;
	int measureLength;
	int beatsPerMeasure;
	int speciesType;
	void writeLowerVoice();
	void writeUpperVoice(int speciesType);
	vector<Note> upperVoice;
};
