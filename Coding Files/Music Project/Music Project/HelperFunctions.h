#pragma once
#include <string>
using namespace std;

// The following 3 functions were used to write/generate code
void GenerateNoteEnum();
void GenerateNoteConversionCases();
string getSuffix(int keyLabelNumber);

// Tests ExportToFile
void tests1();
// Tests WritePhrase
void tests2();