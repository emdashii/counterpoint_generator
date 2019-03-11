#include "WritePhrase.h"
#include <cstdlib>          // for rand
#include <iostream>
#include "GenerateLowerVoice.h"

WritePhrase::WritePhrase(string key, int phraseLength) {
	this->key = key;
	this->phraseLength = phraseLength;
}

WritePhrase::~WritePhrase() {
}

void WritePhrase::setSeed(int seed) {
	srand(seed);
	// For manually entering the seed
	/*int seed;
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
	*/
}


// THIS IS WHERE THE MAGIC HAPPENS (along with everywhere else)


void WritePhrase::writeThePhrase() {
	if (speciesType != 0) {
		writeLowerVoice();
		writeUpperVoice();
	}
	else {
		SpeciesOne imitative;
		imitative.writeImitativeTwoVoices(phraseLength * beatsPerMeasure);
		lowerVoiceI = imitative.getImitativeLower();
		upperVoiceI = imitative.getImitativeUpper();
		upperVoiceI.emplace(upperVoiceI.begin(), 1);
		for (int i = 0; i < lowerVoiceI.size(); i++) {
			lowerVoiceN.push_back(convertIntToNote(lowerVoiceI.at(i)));
			upperVoiceN.push_back(convertIntToNote(upperVoiceI.at(i)));
		}
	}
}

void WritePhrase::printPhraseI() {
	cout << "Phrase in ints: " << endl;
	cout << "Top   : ";
	for (auto i : upperVoiceI) {
		cout << i << "\t";
	}
	cout << endl << "Bottom: ";
	for (auto i : lowerVoiceI) {
		cout << i << "\t";
	}
	cout << endl;
}

void WritePhrase::printPhraseN() {
	cout << "Phrase in Notes: " << endl;
	cout << "Top   : ";
	for (auto i : upperVoiceN) {
		cout << i.getNote() << " ";
	}
	cout << endl << "Bottom: ";
	for (auto i : lowerVoiceN) {
		cout << i.getNote() << " ";
	}
	cout << endl;
}

Note WritePhrase::convertIntToNote(int num) {
	Note key = convertKeyToNote();
	int computeNext = convertScaleDegreeToHalfStep(num) + key.getNote();
	NoteType val = static_cast<NoteType>(computeNext);
	return Note(val, 4);
}

int WritePhrase::convertScaleDegreeToHalfStep(int scaleDegree) {
	int halfStep;
	int expression = (((scaleDegree - 1) % 7) + 1);
	if (expression <= 0) {
		expression += 7;
	}							  
	switch (expression) {
		case 1:
			halfStep = 0;
			break;
		case 2:
			halfStep = 2;
			break;
		case 3:
			halfStep = 4;
			break;
		case 4:
			halfStep = 5;
			break;
		case 5:
			halfStep = 7;
			break;
		case 6:
			halfStep = 9;
			break;
		case 7:
			halfStep = 11;
			break;
		default: // Because of modulo arithmetic, this should never happen
			halfStep = 99;
			cout << "Could not convert scale degree " << scaleDegree << " to half step! Expression: " << expression << endl;
			//throw runtime_error("Could not convert scale degree to half step!");
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

void WritePhrase::writeLowerVoice() {
	GenerateLowerVoice lower(phraseLength * beatsPerMeasure);
	lowerVoiceI = lower.getLowerVoice();
	for (auto i : lowerVoiceI) {
		lowerVoiceN.push_back(convertIntToNote(i));
	}
}

void WritePhrase::writeUpperVoice() {
	if (rand() % 2 == 1) {
		upperVoiceI.push_back(5);
	}
	else {
		upperVoiceI.push_back(8);
	}
	for (int i = 1; i < lowerVoiceI.size() -2; i++) {
		SpeciesOne one;
		one.setNoteBefore(upperVoiceI.at(i - 1));
		one.setNoteBelow(lowerVoiceI.at(i));
		one.setNoteBeforeAndBelow(lowerVoiceI.at(i - 1));
		if (i >= 2) {
			one.setNoteTwoBefore(upperVoiceI.at(i - 2));
		}
		upperVoiceI.push_back(one.chooseNextNote());
	}
	upperVoiceI.push_back(7);
	upperVoiceI.push_back(8);
	for (auto i : upperVoiceI) {
		upperVoiceN.push_back(convertIntToNote(i));
	}
}
