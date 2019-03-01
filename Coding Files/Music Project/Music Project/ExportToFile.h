#pragma once
#include "Note.h"
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
	NoteType convertIntToNote(int num, bool up);
protected:
	Note key;
};

