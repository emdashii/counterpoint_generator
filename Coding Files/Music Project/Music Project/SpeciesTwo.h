#pragma once
#include "SpeciesOne.h"
class SpeciesTwo :
	public SpeciesOne
{
public:
	SpeciesTwo();
	~SpeciesTwo();
	bool melodicRule1();
	bool melodicRule2();
	bool harmonicRule1();
	bool harmonicRule2();
};

