#pragma once
#include "Note.h"
#include "Species.h"
using namespace::std;

// TODO: Complete this class -- Elliott

class SpeciesOne : public Species
{
public:
	SpeciesOne();
	SpeciesOne(Note noteBefore, Note noteBelow, Note beforeAndBelow);
	~SpeciesOne();
	Note chooseNextNote();
	
protected:
	// Now for the species rules.....
	bool melodicRule1a();
	bool melodicRule1b();
	bool harmonicRule1a();
	bool harmonicRule1b();
};

