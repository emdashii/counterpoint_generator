#pragma once
#include "Note.h"
#include "SpeciesTwo.h"
#include "SpeciesFour.h"
#include "SpeciesOne.h"
#include <vector>
using namespace::std;

// TODO: Complete this class

class WritePhrase
{
public:
	WritePhrase(Note key, int measureLength, int beatsPerMeasure, int speciesType);
	~WritePhrase();
	void setSeed(int seed);
	Note getKey() { return key; }
	int getMeasureLength() { return measureLength; }
	int getBeatsPerMeasure() { return beatsPerMeasure; }
	int getSpeciesType() { return speciesType; }
	int getTotalLength() { return measureLength * beatsPerMeasure; }
	Note key;
	int measureLength;
	int beatsPerMeasure;
	int speciesType;
private:
	void writeLowerVoice();
	void writeUpperVoice(int speciesType);
	vector<Note> upperVoice;
};

