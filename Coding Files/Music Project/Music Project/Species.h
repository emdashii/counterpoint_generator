#pragma once
#include "Note.h"
using namespace::std;

class Species
{
public:
	Species();
	~Species();

protected:
	int noteBefore;
	int noteBelow;
	int noteBeforeAndBelow;

	virtual int chooseNextNote() = 0;
};

