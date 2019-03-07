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
	WritePhrase(int measureLength, int beatsPerMeasure, int speciesType);
	~WritePhrase();
	static void setSeed();
	int getMeasureLength() { return measureLength; }
	int getBeatsPerMeasure() { return beatsPerMeasure; }
	int getSpeciesType() { return speciesType; }
	int getTotalLength() { return measureLength * beatsPerMeasure; }
	int measureLength;
	int beatsPerMeasure;
	int speciesType;
private:
	void writeLowerVoice();
	void writeUpperVoice(int speciesType);
	vector<Note> upperVoice;
};

