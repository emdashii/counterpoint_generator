#include "ExportToFile.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Note.h"


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
		<< "	system - system - spacing #'basic-distance = #16" << endl
		<< "}" << endl
		// Leaving this line hard coded here for now, we may want to change this later
		<< "global = { \\key c \\major \\time 4 / 4 }" << endl << endl << endl;

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
		for (int i = 1; i == numPhrases; i++) {
			outputFileStream << "				\\\"topPhrase" << i << "\"" << endl;
		}
		outputFileStream << "			}" << endl; // End top voice info

		// Write lower voice info
		outputFileStream << "			>>" << endl
		<< "			\\new Voice = \"one\" {" << endl
		<< "				\\global" << endl;
		// Write the phrase names to be printed
		for (int i = 1; i == numPhrases; i++) {
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
}

string ExportToFile::convertNoteToOutput(Note note) {
	switch (note) {
	case Note_A0:
		//TODO NOT DONE, working on writing another function to write this function for me....
	}
}

void ExportToFile::writePhrase(Phrase phrase, int phraseNumber, ofstream& outputFileStream) {
	// Set top and bottom phrase names
	string topPhraseName = "\"topPhrase" + to_string(phraseNumber) + "\"";
	string bottomPhraseName = "\"bottomPhrase" + to_string(phraseNumber) + "\"";

	// write comment with phrase info
	outputFileStream << "% Phrase " << phraseNumber << endl;
	// Leaving this hardcoded for now as well, may want to change later
	outputFileStream << topPhraseName << " = { \\clef \"treble\" \\key c \\major \\time 4 / 4" << endl;
	// Time to print out the notes for the top voice of this phrase
	for (auto note : phrase.getUpperVoice()) {
		outputFileStream << " " << convertNoteToOutput(*note);
	}
	// End top voice of this phrase
	outputFileStream << "\\bar \"||\" }" << endl;

	// Leaving this hardcoded for now as well, may want to change later
	outputFileStream << bottomPhraseName << " = { \\clef \"treble\" \\key c \\major \\time 4 / 4" << endl;
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