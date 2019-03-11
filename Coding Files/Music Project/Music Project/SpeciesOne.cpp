#include "SpeciesOne.h"
#include <iostream>


SpeciesOne::SpeciesOne()
{
}


SpeciesOne::~SpeciesOne()
{
}

int SpeciesOne::chooseNextNote() {
	noteOptions.clear();
	h_cannotCrossMelody(); // fills in a range above and equal to note below
	h_avoidDimFifth();
	h_noFourthOrSeventh();

	m_noParallelFifths();
	m_noSimilarFifths();
	m_noParallelOctaves();
	m_noSimilarOctaves();

	int toChoose = (rand() % noteOptions.size());
	return noteOptions.at(toChoose);
}


		// Functions for imitative first species counterpoint

void SpeciesOne::writeImitativeTwoVoices(int length) {
	
	lower = writeImitativeLowerVoice(length);
	for (int i = 0; i < length - 3; i++) {
		int temp = lower.at(i);
		upper.push_back(temp + 4); // Imitative counter point a fifth above
	}
	upper.push_back(7);
	upper.push_back(8);
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

void SpeciesOne::printImitativeCounterpoint() {
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

void SpeciesOne::h_cannotCrossMelody() {
	for (int i = noteBelow; i < 10; i++) {
		noteOptions.push_back(i);
	}
}

void SpeciesOne::h_avoidDimFifth() {
	if ((noteBelow == 0) || (noteBelow == 7)) {
		// 5ths not allowed in this case
		vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 4);
		if (itr != noteOptions.end()) {
			noteOptions.erase(itr);
		}
	}
}

void SpeciesOne::h_noFourthOrSeventh() {
	// Find any perfect fourths
	vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 3);
	if (itr != noteOptions.end()) {
		noteOptions.erase(itr);	// Remove them
	}
	// Find any 7ths
	vector<int>::iterator itrr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 6);
	if (itrr != noteOptions.end()) {
		noteOptions.erase(itrr);	// Remove them
	}
}

void SpeciesOne::m_noParallelFifths() {
	if ((noteBefore - 4) == noteBeforeAndBelow) {
		// 5ths not allowed in this case
		vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 4);
		if (itr != noteOptions.end()) {
			noteOptions.erase(itr);
		}
	}
}

void SpeciesOne::m_noSimilarFifths() {
	if ((noteBeforeAndBelow > noteBelow) && ((noteBefore - 4) >= noteBeforeAndBelow)) {
		// 5ths not allowed in this case
		vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 4);
		if (itr != noteOptions.end()) {
			noteOptions.erase(itr);
		}
	}
	if ((noteBeforeAndBelow < noteBelow) && ((noteBefore - 4) <= noteBeforeAndBelow)) {
		// 5ths not allowed in this case
		vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 4);
		if (itr != noteOptions.end()) {
			noteOptions.erase(itr);
		}
	}
}

void SpeciesOne::m_noParallelOctaves() {
	if ((noteBefore - 7) == noteBeforeAndBelow) {
		// 5ths not allowed in this case
		vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 7);
		if (itr != noteOptions.end()) {
			noteOptions.erase(itr);
		}
	}
}

void SpeciesOne::m_noSimilarOctaves() {
	if ((noteBeforeAndBelow > noteBelow) && ((noteBefore - 7) >= noteBeforeAndBelow)) {
		// 5ths not allowed in this case
		vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 7);
		if (itr != noteOptions.end()) {
			noteOptions.erase(itr);
		}
	}
	if ((noteBeforeAndBelow < noteBelow) && ((noteBefore - 7) <= noteBeforeAndBelow)) {
		// 5ths not allowed in this case
		vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBelow + 7);
		if (itr != noteOptions.end()) {
			noteOptions.erase(itr);
		}
	}
}

void SpeciesOne::m_noSameNote() {
	vector<int>::iterator itr = find(noteOptions.begin(), noteOptions.end(), noteBefore);
	if (itr != noteOptions.end()) {
		noteOptions.erase(itr);
	}
}

