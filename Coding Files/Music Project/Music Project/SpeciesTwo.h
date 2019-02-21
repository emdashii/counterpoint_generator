#pragma once
#include "SpeciesOne.h"

// TODO: Finish after SpeciesOne -- Elliott
class SpeciesTwo :
	public SpeciesOne
{
public:
	SpeciesTwo();
	~SpeciesTwo();
	Note decideNextNote();
	bool melodicRule2a();
	bool melodicRule2b();
	bool harmonicRule2a();
	bool harmonicRule2b();
};

