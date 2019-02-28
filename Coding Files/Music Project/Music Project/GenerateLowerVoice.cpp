#include "GenerateLowerVoice.h"
#include <vector>



GenerateLowerVoice::GenerateLowerVoice()
{
	
}
//TODO: Finish generateLowerVoice
GenerateLowerVoice::GenerateLowerVoice(Note key, int length) {
	this->key = key;
	this->length = length;
	
	lowerVoice.push_back(key);
	int secondNote = 0;
	switch (rand() % 2) {
		case 0:
			secondNote = 8;
		case 1:
			secondNote = 5;
		default:
			secondNote = 0;
	}
	lowerVoice.push_back(convertIntervalToKey(secondNote));
	for (int i = 0; i <= length-2, i++) {
		lowerVoice.push_back(convertIntervalToKey(pickRandomInterval()));
	}
}


GenerateLowerVoice::~GenerateLowerVoice()
{
}

int GenerateLowerVoice::pickRandomInterval() {
	switch (rand() % 20) {
	case 0:
	case 1:
	case 2:
		return 1;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		return 2;
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		return 3;
		break;
	case 12:
	case 13:
	case 14:
		return 5;
		break;
	case 15:
	case 16:
		return 6;
		break;
	default:
		return 2;
	}
}
//TODO: Finish function convertIntervalToKey
Note GenerateLowerVoice::convertIntervalToKey(Note noteBefore, int interval) {
	switch(interval) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
	}
}
