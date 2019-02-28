#include "WritePhrase.h"
#include <cstdlib>          // for rand
#include <iostream>


WritePhrase::WritePhrase()
{
}


WritePhrase::WritePhrase(Note key, int measureLength, int beatsPerMeasure, int speciesType) {
	// 
}

WritePhrase::~WritePhrase()
{
}

void WritePhrase::setSeed(int seed) {
	int seed;
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
