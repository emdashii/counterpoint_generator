#include "GenerateLowerVoice.h"
#include <vector>
#include <iostream>


//TODO: Finish generateLowerVoice
GenerateLowerVoice::GenerateLowerVoice(int length) {
	this->length = length;

	lowerVoice.push_back(1);

	for (int i = 0; i < length - 3; i++) {
		int nextNote;
		if (lowerVoice.back() < -4) {
			nextNote = lowerVoice.back() + pickRandomInterval() -1;
		}
		else if (lowerVoice.back() > 5) {
			nextNote = lowerVoice.back() - pickRandomInterval() -1;
		}
		else if (rand() % 2 == 0) {
			nextNote = lowerVoice.back() + pickRandomInterval() -1;
		}
		else {
			nextNote = lowerVoice.back() - pickRandomInterval() -1;
		}
		lowerVoice.push_back(nextNote);
	}
	lowerVoice.push_back(2);
	lowerVoice.push_back(1);
}


GenerateLowerVoice::~GenerateLowerVoice()
{
}

int GenerateLowerVoice::pickRandomInterval() {
	switch (rand() % 20) {
	case 0:
	case 1:
	case 2:
		return 1;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		return 2;
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		return 3;
		break;
	case 12:
	case 13:
	case 14:
		return 5;
		break;
	case 15:
	case 16:
		return 6;
		break;
	default:
		return 2;
	}
}

void GenerateLowerVoice::printLowerVoice() {
	cout << "Lower voice: ";
	for (auto note : lowerVoice) {
		cout << note << "\t";
	}
	cout << endl;
}

void GenerateLowerVoice::writeCheatTwoVoices() {
	vector<int> lower;
	vector<int> upper;
	lower = writeCheatLowerVoice();
	for (int i = 0; i < length - 3; i++) {
		int temp;
		temp = lower.at(i);
		upper.push_back(temp + 4);
	}
	upper.push_back(7);
	upper.push_back(8);
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

vector<int> GenerateLowerVoice::writeCheatLowerVoice() {
	vector<int> cheatLowerVoice;
	cheatLowerVoice.push_back(1);

	for (int i = 0; i < length - 3; i++) {
		int nextNote;
		if (cheatLowerVoice.back() < -4) {
			nextNote = cheatLowerVoice.back() + pickCheatUp() - 1;
		}
		else if (cheatLowerVoice.back() > 5) {
			nextNote = cheatLowerVoice.back() - pickCheatDown() - 1;
		}
		else if (rand() % 2 == 0) {
			nextNote = cheatLowerVoice.back() - pickCheatDown() - 1;
		}
		else {
			nextNote = cheatLowerVoice.back() + pickCheatUp() - 1;
		}
		cheatLowerVoice.push_back(nextNote);
	}
	cheatLowerVoice.push_back(2);
	cheatLowerVoice.push_back(1);
	return cheatLowerVoice;
}

int GenerateLowerVoice::pickCheatUp() {
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

int GenerateLowerVoice::pickCheatDown() {
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
