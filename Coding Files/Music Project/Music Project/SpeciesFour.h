#pragma once
#include "SpeciesOne.h"

// TODO: Finish after SpeciesTwo -- Elliott
class SpeciesFour :
	public SpeciesOne
{
public:
	SpeciesFour();
	~SpeciesFour();
	Note decideNextNote();
	bool melodicRule4a();
	bool melodicRule4b();
	bool harmonicRule4a();
	bool harmonicRule4b();
};

