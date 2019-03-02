#pragma once
#include "Note.h"
#include <string>
using namespace::std;

// TODO: Complete this class -- Caleb
class ExportToFile
{
public:
	ExportToFile();
	~ExportToFile();
	// Run this class to combine everything and create a new file.
	void baseFileHeader();
	void writeIntoFile();
	Note convertIntToNote(int num);
	int convertScaleDegreeToHalfStep(int halfStep);
	Note convertKeyToNote();
protected:
	string key;
};

