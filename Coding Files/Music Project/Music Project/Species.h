#pragma once
#include "Note.h"
using namespace::std;

class Species
{
public:
	Species();
	~Species();

protected:
	Note noteBefore;
	Note noteBelow;
	Note beforeAndBelow;

	virtual Note chooseNextNote() = 0;
};

