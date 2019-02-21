#pragma once
#include "SpeciesOne.h"
class SpeciesFour :
	public SpeciesOne
{
public:
	SpeciesFour();
	~SpeciesFour();
	void decideNextNote();
	bool melodicRule1();
	bool melodicRule2();
	bool harmonicRule1();
	bool harmonicRule2();
};

