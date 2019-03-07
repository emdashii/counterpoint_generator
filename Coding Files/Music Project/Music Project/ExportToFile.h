#pragma once
#include "Note.h"
#include <string>
#include <vector>
using namespace::std;

// TODO: Complete this class -- Caleb
class ExportToFile
{
public:
	ExportToFile(vector<Note> upperVoice, vector<Note> lowerVoice, string fileName);
	~ExportToFile();
	void exportUpperVoice();
	void exportLowerVoice();

	// NOTE -- https://www.hacklily.org/
	
protected:
	
};

