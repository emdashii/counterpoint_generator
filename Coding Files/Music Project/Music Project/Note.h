#pragma once
using namespace::std;

/*
 * Refer to the keyboard layout picture in non-coding related folder for the keyboard layout this was based off of
 * Basically each key is assigned a number corresponding to its position on an 88 key keyboard 
 * This should make counting half steps very easy, just subtract the two notes from each other  
 * and you got the number of half steps between them
 * 
 */
enum NoteType {
	Note_A0 = 0,
	Note_A0_sharp = 1,
	Note_B0_flat = 1,
	Note_B0 = 2,
	Note_C1 = 3,
	Note_C1_sharp = 4,
	Note_D1_flat = 4,
	Note_D1 = 5,
	Note_D1_sharp = 6,
	Note_E1_flat = 6,
	Note_E1 = 7,
	Note_F1 = 8,
	Note_F1_sharp = 9,
	Note_G1_flat = 9,
	Note_G1 = 10,
	Note_G1_sharp = 11,
	Note_A1_flat = 11,
	Note_A1 = 12,
	Note_A1_sharp = 13,
	Note_B1_flat = 13,
	Note_B1 = 14,
	Note_C2 = 15,
	Note_C2_sharp = 16,
	Note_D2_flat = 16,
	Note_D2 = 17,
	Note_D2_sharp = 18,
	Note_E2_flat = 18,
	Note_E2 = 19,
	Note_F2 = 20,
	Note_F2_sharp = 21,
	Note_G2_flat = 21,
	Note_G2 = 22,
	Note_G2_sharp = 23,
	Note_A2_flat = 23,
	Note_A2 = 24,
	Note_A2_sharp = 25,
	Note_B2_flat = 25,
	Note_B2 = 26,
	Note_C3 = 27,
	Note_C3_sharp = 28,
	Note_D3_flat = 28,
	Note_D3 = 29,
	Note_D3_sharp = 30,
	Note_E3_flat = 30,
	Note_E3 = 31,
	Note_F3 = 32,
	Note_F3_sharp = 33,
	Note_G3_flat = 33,
	Note_G3 = 34,
	Note_G3_sharp = 35,
	Note_A3_flat = 35,
	Note_A3 = 36,
	Note_A3_sharp = 37,
	Note_B3_flat = 37,
	Note_B3 = 38,
	Note_C4 = 39,	// Middle C
	Note_C4_sharp = 40,
	Note_D4_flat = 40,
	Note_D4 = 41,
	Note_D4_sharp = 42,
	Note_E4_flat = 42,
	Note_E4 = 43,
	Note_F4 = 44,
	Note_F4_sharp = 45,
	Note_G4_flat = 45,
	Note_G4 = 46,
	Note_G4_sharp = 47,
	Note_A4_flat = 47,
	Note_A4 = 48,
	Note_A4_sharp = 49,
	Note_B4_flat = 49,
	Note_B4 = 50,
	Note_C5 = 51,
	Note_C5_sharp = 52,
	Note_D5_flat = 52,
	Note_D5 = 53,
	Note_D5_sharp = 54,
	Note_E5_flat = 54,
	Note_E5 = 55,
	Note_F5 = 56,
	Note_F5_sharp = 57,
	Note_G5_flat = 57,
	Note_G5 = 58,
	Note_G5_sharp = 59,
	Note_A5_flat = 59,
	Note_A5 = 60,
	Note_A5_sharp = 61,
	Note_B5_flat = 61,
	Note_B5 = 62,
	Note_C6 = 63,
	Note_C6_sharp = 64,
	Note_D6_flat = 64,
	Note_D6 = 65,
	Note_D6_sharp = 66,
	Note_E6_flat = 66,
	Note_E6 = 67,
	Note_F6 = 68,
	Note_F6_sharp = 69,
	Note_G6_flat = 69,
	Note_G6 = 70,
	Note_G6_sharp = 71,
	Note_A6_flat = 71,
	Note_A6 = 72,
	Note_A6_sharp = 73,
	Note_B6_flat = 73,
	Note_B6 = 74,
	Note_C7 = 75,
	Note_C7_sharp = 76,
	Note_D7_flat = 76,
	Note_D7 = 77,
	Note_D7_sharp = 78,
	Note_E7_flat = 78,
	Note_E7 = 79,
	Note_F7 = 80,
	Note_F7_sharp = 81,
	Note_G7_flat = 81,
	Note_G7 = 82,
	Note_G7_sharp = 83,
	Note_A7_flat = 83,
	Note_A7 = 84,
	Note_A7_sharp = 85,
	Note_B7_flat = 85,
	Note_B7 = 86,
	Note_C8 = 87,
};

// TODO: Complete this class
class Note
{
public:
	
	Note(NoteType note = Note_C4, int length = 4);
	~Note();
	NoteType getNote() { return note; }
	int getLength() { return length; }
	void setNote(NoteType note) { this->note = note; }
	void setLength(int length) { this->length = length; }
	NoteType convertIntToNote(int num, bool up);
private:
	NoteType note;
	int length;
};

