#include "Note.h"

Note::Note(NoteType note, int length) {
	this->note = note;
	this->length = length;
	if (note > 88 || note < 0) {
		cout << "Note constructor too large... " << note << endl;
	}
}