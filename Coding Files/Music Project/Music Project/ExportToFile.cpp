#include "ExportToFile.h"
#include <cstdlib>
#include <iostream>
#include "Note.h"


ExportToFile::ExportToFile()
{
}


ExportToFile::~ExportToFile()
{
}

//TODO: Finish function convertIntervalToNote
Note ExportToFile::convertIntToNote(int num) {
	Note temp;
	
	return temp;
}

int ExportToFile::convertScaleDegreeToHalfStep(int scaleDegree) {
	int halfStep;
	switch (((scaleDegree-1) % 7) + 1) {
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
		default:		// Because of modulo arithmetic, this should never happen
			halfStep = 999;
			//cerr << "ConvertScaleDegreeToHalfStep failed." << endl;
			exit(1);
			break;
		}
	return ((scaleDegree-1)/7)*12 + halfStep;
}

Note ExportToFile::convertKeyToNote() {
	Note toReturn(Note_C4);
	if (key == "C") {
		toReturn.setNote(Note_C4);
		return toReturn;
	}
	// Use else if for the rest of the key signatures
	else {
		return toReturn;
	}
}
