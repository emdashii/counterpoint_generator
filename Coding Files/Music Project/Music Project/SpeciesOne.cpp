#include "SpeciesOne.h"
#include <iostream>


SpeciesOne::SpeciesOne()
{
}


SpeciesOne::~SpeciesOne()
{
}

int SpeciesOne::chooseNextNote() {
	return 0;
}


		// Functions for imitative first species counterpoint

void SpeciesOne::writeImitativeTwoVoices(int length) {
	vector<int> lower;
	vector<int> upper;
	lower = writeImitativeLowerVoice(length);
	for (int i = 0; i < length - 3; i++) {
		int temp = lower.at(i);
		upper.push_back(temp + 4); // Imitative counter point a fifth above
	}
	upper.push_back(7);
	upper.push_back(8);

	printImitativeCounterpoint(upper, lower); 
}

vector<int> SpeciesOne::writeImitativeLowerVoice(int length) {
	vector<int> ImitativeLowerVoice;
	ImitativeLowerVoice.push_back(1);

	for (int i = 0; i < length - 3; i++) {
		int nextNote;
		if (ImitativeLowerVoice.back() < -4) { // Sets bar for how low it will go
			nextNote = ImitativeLowerVoice.back() + pickImitativeUp() - 1;
		}
		else if (ImitativeLowerVoice.back() > 5) { // Sets bar for how high it will go
			nextNote = ImitativeLowerVoice.back() - pickImitativeDown() - 1;
		}
		else if (rand() % 2 == 0) {
			nextNote = ImitativeLowerVoice.back() - pickImitativeDown() - 1;
		}
		else {
			nextNote = ImitativeLowerVoice.back() + pickImitativeUp() - 1;
		}
		ImitativeLowerVoice.push_back(nextNote);
	}
	ImitativeLowerVoice.push_back(2);
	ImitativeLowerVoice.push_back(1);
	return ImitativeLowerVoice;
}

int SpeciesOne::pickImitativeUp() { // Returns the same note, a third, or a fifth above
	switch (rand() % 9) {
	case 0:
		return 1;
		break;
	case 1:
	case 2:
	case 3:
	case 4:
		return 3;
		break;
	case 5:
	case 6:
		return 5;
		break;
	default:
		return 3;
		break;
	}
}

int SpeciesOne::pickImitativeDown() { // Returns the same note, a second, or a fourth below
	switch (rand() % 7) {
	case 0:
		return 1;
		break;
	case 1:
	case 2:
	case 3:
	case 4:
		return 2;
		break;
	case 5:
	case 6:
		return 4;
		break;
	default:
		return 2;
		break;
	}
}

void SpeciesOne::printImitativeCounterpoint(vector<int> upper, vector<int> lower) {
	cout << "Top:" << "\t\t";
	for (auto note : upper) {
		cout << note << "\t";
	}
	cout << endl << "Bottom:" << "\t";
	for (auto note : lower) {
		cout << note << "\t";
	}
	cout << endl;
}

