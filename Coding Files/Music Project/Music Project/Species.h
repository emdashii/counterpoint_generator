#pragma once
#include "Note.h"
using namespace::std;

class Species
{
public:
	Species();
	~Species();
	void setNoteBefore(int noteBefore) { this->noteBefore = noteBefore; }
	void setNoteBelow(int noteBelow) { this->noteBelow = noteBelow; }
	void setNoteBeforeAndBelow(int noteBeforeAndBelow) { this->noteBeforeAndBelow = noteBeforeAndBelow; }
	int getNoteBefore() { return noteBefore; }
	int getNoteBelow() { return noteBelow; }
	int getNoteBeforeAndBelow() { return noteBeforeAndBelow; }
	
protected:
	int noteBefore;
	int noteBelow;
	int noteBeforeAndBelow;

	virtual int chooseNextNote() = 0;
};

