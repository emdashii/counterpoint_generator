#pragma once
#include "Note.h"

class SpeciesOne
{
public:
	SpeciesOne();
	SpeciesOne(Note noteBefore, Note noteBelow, Note beforeAndBelow);
	~SpeciesOne();
	int decideNextNote();
	
protected:
	Note noteBefore;
	Note noteBelow;
	Note beforeAndBelow;
	// Now for the species rules.....
	bool melodicRule1();
	bool melodicRule2();
	bool harmonicRule1();
	bool harmonicRule2();
};

