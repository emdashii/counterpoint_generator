#pragma once
#include "Note.h"

// TODO: Complete this class -- Elliott

class SpeciesOne
{
public:
	SpeciesOne();
	SpeciesOne(Note noteBefore, Note noteBelow, Note beforeAndBelow);
	~SpeciesOne();
	virtual Note decideNextNote();
	
protected:
	Note noteBefore;
	Note noteBelow;
	Note beforeAndBelow;
	// Now for the species rules.....
	bool melodicRule1a();
	bool melodicRule1b();
	bool harmonicRule1a();
	bool harmonicRule1b();
};

