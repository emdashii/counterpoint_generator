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

Note ExportToFile::convertIntToNote(int num) {
	Note key = convertKeyToNote();
	int computeNext = convertScaleDegreeToHalfStep(num) + key.getNote();
	NoteType val = static_cast<NoteType>(computeNext);
	Note newNote(val, 4);
	return newNote;
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
	else if (key == "Db") {
		toReturn.setNote(Note_D4_flat);
		return toReturn;
	}
	else if (key == "D") {
		toReturn.setNote(Note_D4);
		return toReturn;
	}
	else if (key == "Eb") {
		toReturn.setNote(Note_E4_flat);
		return toReturn;
	}
	else if (key == "E") {
		toReturn.setNote(Note_E4);
		return toReturn;
	}
	else if (key == "F") {
		toReturn.setNote(Note_F4);
		return toReturn;
	}
	else if (key == "F#") {
		toReturn.setNote(Note_F4_sharp);
		return toReturn;
	}
	else if (key == "G") {
		toReturn.setNote(Note_G4);
		return toReturn;
	}
	else if (key == "Ab") {
		toReturn.setNote(Note_A3_flat);
		return toReturn;
	}
	else if (key == "A") {
		toReturn.setNote(Note_A3);
		return toReturn;
	}
	else if (key == "Bb") {
		toReturn.setNote(Note_B3_flat);
		return toReturn;
	}
	else if (key == "B") {
		toReturn.setNote(Note_B3);
		return toReturn;
	}
	else {
		return toReturn;
	}
}
