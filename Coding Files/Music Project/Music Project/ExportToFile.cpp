#include "ExportToFile.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Note.h"


ExportToFile::ExportToFile(string fileName, string musicTitle, string composer, string key) : title(musicTitle), composer(composer) {
	//TODO verify key before assignment
	this->key = key;

	//TODO may want to change this ending to proper lily pond file extension, but leaving like this for now for testing purposes
	// Put ending of .txt on the end of the filename if it doesn't have that ending already
	if (fileName.length() < 4) {
		fileName += ".txt";
	}
	else if (fileName.compare(fileName.length() - 4, fileName.length(), ".txt")) { // returns 0 if it does have that ending
		fileName += ".txt";
	}

	//TODO revise this
	// // Check to see if that file already exists, so we don't accidentally overwrite it or have to append to it
	// ifstream inputFileStream(outputFileName.c_str());
	// if (inputFileStream) {
	// 	cout << "Warning, that file already exists! Please choose a new file name." << endl;
	// 	invalidName = true;
	// 	inputFileStream.close();
	// 	continue;
	// }
	// inputFileStream.close();


	this->fileName = fileName;
}

void ExportToFile::addPhrase(Phrase* phrase) {
	phrases.push_back(phrase);
}

void ExportToFile::WriteOutput() {

	// Open/create file for output
	ofstream outputFileStream(fileName);

	// Verify opening/creating file was successful
	if (!outputFileStream) {
		throw runtime_error("Couldn't open file for output!");
	}

	// Else use that file stream and start writing our output

	// Output general header information
	outputFileStream << "\\header {" << endl
		<< "title = \"" << title << "\"" << endl
		<< "composer = \"" << composer << "\"" << endl
		<< "tagline = \"Written By Caleb Nelson and Elliott Claus's Counterpoint Generation Program\"" << endl
		<< "}" << endl
		<< "\\paper {" << endl
		<< "	system-system-spacing #'basic-distance = #16" << endl
		<< "}" << endl
		// Leaving this line hard coded here for now, we may want to change this later
		<< "global = { \\key c \\major \\time 4/4 }" << endl << endl << endl;

	// Loop through phrases to be printed
	int numPhrases = 0;
	for (auto phrase : phrases) {
		// Write the current phrase -- Writes the upper and lower voice
		writePhrase(*phrase, ++numPhrases, outputFileStream);
	} // End of loop for printing phrases

	// Output final info for file
	outputFileStream << "\\score {" << endl
		<< "	<<" << endl
		<< "		<<" << endl
		<< "			\\new Voice = \"one\" {" << endl
		<< "				\\global" << endl;
	// Write the phrase names to be printed
	for (int i = 1; i <= numPhrases; i++) {
		outputFileStream << "				\\\"topPhrase" << i << "\"" << endl;
	}
	outputFileStream << "			}" << endl; // End top voice info

	// Write lower voice info
	outputFileStream << "			>>" << endl
		<< "			\\new Voice = \"one\" {" << endl
		<< "				\\global" << endl;
	// Write the phrase names to be printed
	for (int i = 1; i <= numPhrases; i++) {
		outputFileStream << "				\\\"bottomPhrase" << i << "\"" << endl;
	}
	outputFileStream << "			}" << endl; // End bottom voice info

	// Final closing for file
	outputFileStream << "	>>" << endl
		<< "		\\layout{}" << endl
		<< "		\\midi{}" << endl
		<< "}" << endl;

	// Close the file
	outputFileStream.close();

	// Report Success
	cout << "Final output file successfully created!" << endl;
}

void ExportToFile::writePhrase(Phrase phrase, int phraseNumber, ofstream& outputFileStream) {
	// Set top and bottom phrase names
	string topPhraseName = "\"topPhrase" + to_string(phraseNumber) + "\"";
	string bottomPhraseName = "\"bottomPhrase" + to_string(phraseNumber) + "\"";

	// write comment with phrase info
	outputFileStream << "% Phrase " << phraseNumber << endl;
	// Leaving this hardcoded for now as well, may want to change later
	outputFileStream << topPhraseName << " = { \\clef \"treble\" \\key c \\major \\time 4/4" << endl;
	// Time to print out the notes for the top voice of this phrase
	for (auto note : phrase.getUpperVoice()) {
		outputFileStream << " " << convertNoteToOutput(*note);
	}
	// End top voice of this phrase
	outputFileStream << "\\bar \"||\" }" << endl;

	// Leaving this hardcoded for now as well, may want to change later
	outputFileStream << bottomPhraseName << " = { \\clef \"treble\" \\key c \\major \\time 4/4" << endl;
	// Time to print out the notes for the bottom voice of this phrase
	for (auto note : phrase.getLowerVoice()) {
		outputFileStream << " " << convertNoteToOutput(*note);
	}
	// End bottom voice of this phrase
	outputFileStream << "}" << endl;
}

// General output outline
/*
 
\header {
title = "Epic Title"
composer = "Cool Composer"
tagline = "Written By Caleb Nelson and Elliott Claus's Counterpoint Generation Program"
}

\paper {
  system-system-spacing #'basic-distance = #16
}
global = { \key c \major \time 4/4 }


% Phrase one. Imitative counterpoint a 5th above. C major.
"topPhrase1" = { \clef "treble" \key c \major \time 4/4
NOTES_HERE \bar "||" }
"bottomPhrase1" = { \clef "treble" \key c \major \time 4/4
NOTES_HERE}



\score {
  <<
	<<
	  \new Voice = "one" {
		\global
		\"topPhrase1"
	  }
	  >>
	  \new Voice = "two" {
		\global
		\"bottomPhrase1"
	  }
  >>
	\layout{}
	\midi{}
}

 */

string ExportToFile::convertNoteToOutput(Note note) {
	switch (note.getNote()) {
	case Note_A0:
		return "a,,," + to_string(note.getLength());
		break;
	case Note_A0_sharp:
		return "ais,,," + to_string(note.getLength());
		break;
	case Note_B0:
		return "b,,," + to_string(note.getLength());
		break;
	case Note_C1:
		return "c,," + to_string(note.getLength());
		break;
	case Note_C1_sharp:
		return "cis,," + to_string(note.getLength());
		break;
	case Note_D1:
		return "d,," + to_string(note.getLength());
		break;
	case Note_D1_sharp:
		return "dis,," + to_string(note.getLength());
		break;
	case Note_E1:
		return "e,," + to_string(note.getLength());
		break;
	case Note_F1:
		return "f,," + to_string(note.getLength());
		break;
	case Note_F1_sharp:
		return "fis,," + to_string(note.getLength());
		break;
	case Note_G1:
		return "g,," + to_string(note.getLength());
		break;
	case Note_G1_sharp:
		return "gis,," + to_string(note.getLength());
		break;
	case Note_A1:
		return "a,," + to_string(note.getLength());
		break;
	case Note_A1_sharp:
		return "ais,," + to_string(note.getLength());
		break;
	case Note_B1:
		return "b,," + to_string(note.getLength());
		break;
	case Note_C2:
		return "c," + to_string(note.getLength());
		break;
	case Note_C2_sharp:
		return "cis," + to_string(note.getLength());
		break;
	case Note_D2:
		return "d," + to_string(note.getLength());
		break;
	case Note_D2_sharp:
		return "dis," + to_string(note.getLength());
		break;
	case Note_E2:
		return "e," + to_string(note.getLength());
		break;
	case Note_F2:
		return "f," + to_string(note.getLength());
		break;
	case Note_F2_sharp:
		return "fis," + to_string(note.getLength());
		break;
	case Note_G2:
		return "g," + to_string(note.getLength());
		break;
	case Note_G2_sharp:
		return "gis," + to_string(note.getLength());
		break;
	case Note_A2:
		return "a," + to_string(note.getLength());
		break;
	case Note_A2_sharp:
		return "ais," + to_string(note.getLength());
		break;
	case Note_B2:
		return "b," + to_string(note.getLength());
		break;
	case Note_C3:
		return "c" + to_string(note.getLength());
		break;
	case Note_C3_sharp:
		return "cis" + to_string(note.getLength());
		break;
	case Note_D3:
		return "d" + to_string(note.getLength());
		break;
	case Note_D3_sharp:
		return "dis" + to_string(note.getLength());
		break;
	case Note_E3:
		return "e" + to_string(note.getLength());
		break;
	case Note_F3:
		return "f" + to_string(note.getLength());
		break;
	case Note_F3_sharp:
		return "fis" + to_string(note.getLength());
		break;
	case Note_G3:
		return "g" + to_string(note.getLength());
		break;
	case Note_G3_sharp:
		return "gis" + to_string(note.getLength());
		break;
	case Note_A3:
		return "a" + to_string(note.getLength());
		break;
	case Note_A3_sharp:
		return "ais" + to_string(note.getLength());
		break;
	case Note_B3:
		return "b" + to_string(note.getLength());
		break;
	case Note_C4:
		return "c'" + to_string(note.getLength());
		break;
	case Note_C4_sharp:
		return "cis'" + to_string(note.getLength());
		break;
	case Note_D4:
		return "d'" + to_string(note.getLength());
		break;
	case Note_D4_sharp:
		return "dis'" + to_string(note.getLength());
		break;
	case Note_E4:
		return "e'" + to_string(note.getLength());
		break;
	case Note_F4:
		return "f'" + to_string(note.getLength());
		break;
	case Note_F4_sharp:
		return "fis'" + to_string(note.getLength());
		break;
	case Note_G4:
		return "g'" + to_string(note.getLength());
		break;
	case Note_G4_sharp:
		return "gis'" + to_string(note.getLength());
		break;
	case Note_A4:
		return "a'" + to_string(note.getLength());
		break;
	case Note_A4_sharp:
		return "ais'" + to_string(note.getLength());
		break;
	case Note_B4:
		return "b'" + to_string(note.getLength());
		break;
	case Note_C5:
		return "c''" + to_string(note.getLength());
		break;
	case Note_C5_sharp:
		return "cis''" + to_string(note.getLength());
		break;
	case Note_D5:
		return "d''" + to_string(note.getLength());
		break;
	case Note_D5_sharp:
		return "dis''" + to_string(note.getLength());
		break;
	case Note_E5:
		return "e''" + to_string(note.getLength());
		break;
	case Note_F5:
		return "f''" + to_string(note.getLength());
		break;
	case Note_F5_sharp:
		return "fis''" + to_string(note.getLength());
		break;
	case Note_G5:
		return "g''" + to_string(note.getLength());
		break;
	case Note_G5_sharp:
		return "gis''" + to_string(note.getLength());
		break;
	case Note_A5:
		return "a''" + to_string(note.getLength());
		break;
	case Note_A5_sharp:
		return "ais''" + to_string(note.getLength());
		break;
	case Note_B5:
		return "b''" + to_string(note.getLength());
		break;
	case Note_C6:
		return "c'''" + to_string(note.getLength());
		break;
	case Note_C6_sharp:
		return "cis'''" + to_string(note.getLength());
		break;
	case Note_D6:
		return "d'''" + to_string(note.getLength());
		break;
	case Note_D6_sharp:
		return "dis'''" + to_string(note.getLength());
		break;
	case Note_E6:
		return "e'''" + to_string(note.getLength());
		break;
	case Note_F6:
		return "f'''" + to_string(note.getLength());
		break;
	case Note_F6_sharp:
		return "fis'''" + to_string(note.getLength());
		break;
	case Note_G6:
		return "g'''" + to_string(note.getLength());
		break;
	case Note_G6_sharp:
		return "gis'''" + to_string(note.getLength());
		break;
	case Note_A6:
		return "a'''" + to_string(note.getLength());
		break;
	case Note_A6_sharp:
		return "ais'''" + to_string(note.getLength());
		break;
	case Note_B6:
		return "b'''" + to_string(note.getLength());
		break;
	case Note_C7:
		return "c''''" + to_string(note.getLength());
		break;
	case Note_C7_sharp:
		return "cis''''" + to_string(note.getLength());
		break;
	case Note_D7:
		return "d''''" + to_string(note.getLength());
		break;
	case Note_D7_sharp:
		return "dis''''" + to_string(note.getLength());
		break;
	case Note_E7:
		return "e''''" + to_string(note.getLength());
		break;
	case Note_F7:
		return "f''''" + to_string(note.getLength());
		break;
	case Note_F7_sharp:
		return "fis''''" + to_string(note.getLength());
		break;
	case Note_G7:
		return "g''''" + to_string(note.getLength());
		break;
	case Note_G7_sharp:
		return "gis''''" + to_string(note.getLength());
		break;
	case Note_A7:
		return "a''''" + to_string(note.getLength());
		break;
	case Note_A7_sharp:
		return "ais''''" + to_string(note.getLength());
		break;
	case Note_B7:
		return "b''''" + to_string(note.getLength());
		break;
	case Note_C8:
		return "c'''''" + to_string(note.getLength());
		break;
	default:
		//TODO Fixme
		string test = to_string(note.getNote());
		throw runtime_error("Error, could not convert note to proper output for lily pond!" + " Test, Note int is: " + note.getNote() );
	}
}