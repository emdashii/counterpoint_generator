#include "WritePhrase.h"
#include <cstdlib>          // for rand
#include <iostream>
#include "GenerateLowerVoice.h"


WritePhrase::WritePhrase(int measureLength, int beatsPerMeasure, int speciesType) {
	//GenerateLowerVoice(measureLength) lower;
	//vector<int> lowerVoice = lower.getLowerVoice;
	//SpeciesOne upper;
}

WritePhrase::~WritePhrase() {
}

void WritePhrase::setSeed() {
	double seed;
	cout << "Enter seed for random numbers: ";
	cin >> seed;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Try again: " << endl;
		cin >> seed;
	}
	srand(seed);
	cout << "Seed set to " << seed << endl;
}

Note WritePhrase::convertIntToNote(int num) {
	Note key = convertKeyToNote();
	int computeNext = convertScaleDegreeToHalfStep(num) + key.getNote();
	NoteType val = static_cast<NoteType>(computeNext);
	return Note(val, 4);
}

int WritePhrase::convertScaleDegreeToHalfStep(int scaleDegree) {
	int halfStep;
	switch (((scaleDegree - 1) % 7) + 1) {
		case 0:
			halfStep = 0;
			break;
		case 1:
			halfStep = 2;
			break;
		case 2:
			halfStep = 4;
			break;
		case 3:
			halfStep = 5;
			break;
		case 4:
			halfStep = 7;
			break;
		case 5:
			halfStep = 9;
			break;
		case 6:
			halfStep = 11;
			break;
		default: // Because of modulo arithmetic, this should never happen
			halfStep = 999;
			throw runtime_error("Could not convert scale degree to half step!");
	}
	return ((scaleDegree - 1) / 7) * 12 + halfStep;
}

Note WritePhrase::convertKeyToNote() {
	if (key == "C") {
		return Note(Note_C4);
	}
	else if (key == "Db") {
		return Note(Note_D4_flat);
	}
	else if (key == "D") {
		return Note(Note_D4);
	}
	else if (key == "Eb") {
		return Note(Note_E4_flat);
	}
	else if (key == "E") {
		return Note(Note_E4);
	}
	else if (key == "F") {
		return Note(Note_F4);
	}
	else if (key == "F#") {
		return Note(Note_F4_sharp);
	}
	else if (key == "G") {
		return Note(Note_G4);
	}
	else if (key == "Ab") {
		return Note(Note_A3_flat);
	}
	else if (key == "A") {
		return Note(Note_A3);
	}
	else if (key == "Bb") {
		return Note(Note_B3_flat);
	}
	else if (key == "B") {
		return Note(Note_B3);
	}
	else {
		throw runtime_error("Cannot convert key to note!");
	}
}
