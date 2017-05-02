#include "stdafx.h"
#include "Emulator.h"
#include "Errors.h"
/**/
/*
NAME

Emulator::InsertMemory - Inserts contents of program into memory. 

SYNOPSIS

bool Emulator::InsertMemory(int a_location, int a_contents);
a_location --> The location in the memory array to place contents.
a_contents --> The contents to be stored in the m_memory array. 

DESCRIPTION

This function will place a_contents into a_location. It checks that a_location is
a valid location in the array, so it must be smaller than or equal to 9999. If the 
location is not valid, it is not placed into memory.

RETURNS

The function returns true if a_location was a valid location, and a_contents was intserted.
The function returns false if a_location was not valid, and nothing is inserted.

AUTHOR

Nicole Millian

DATE

8:34pm 12/22/2015

*/
/**/
bool Emulator::InsertMemory(int a_location, int a_contents) {
	if (a_location <= 9999) {
		m_memory[a_location] = a_contents;
		count++;
		return true;
	}
	else {
		return false;
	}
}
/*bool Emulator::InsertMemory(int a_location, int a_contents) */

/**/
/*
NAME

Emulator::ParseNum - Parses contents into an opcode and an address.

SYNOPSIS

void Emulator::ParseNum(int a_loc, int&a_opcode, int&a_address);
a_loc --> The location of contents to parse.
a_opcode --> The opcode that was parsed from the contents, passed by reference.
a_address --> The address that was parsed from the contents, passed by reference.

DESCRIPTION

This function will parse the contents found at m_memory[a_loc] by dividing the 
contents by 10000 to get a_opcode and using modulus 10000 to get the a_address.

RETURNS

The function is void, so there are no returns.

AUTHOR

Nicole Millian

DATE

8:41pm 12/22/2015

*/
/**/
void Emulator::ParseNum(int a_loc, int&a_opcode, int&a_address) {
	int contents = m_memory[a_loc];
	a_opcode = contents / 10000;
	a_address = contents % 10000;
}
/* void Emulator::ParseNum(int a_loc, int&a_opcode, int&a_address)*/

/**/
/*
NAME

Emulator::RunProgram() - adds a new symbol to the symbol table.

SYNOPSIS

bool Emulator::RunProgram();
No arguments are passed to the function.

DESCRIPTION

This function will run the emulator, starting at location 100, as specified in the
instructions. Each instruction is parsed into an opcode and address using the ParseNum function.
The opcode is used in order to determine which case it falls under, and the address is used to 
determine where the contents are in memory. 

RETURNS

The function returns true at the end of the emulation.

AUTHOR

Nicole Millian

DATE

8:55pm 12/22/2015

*/
/**/
bool Emulator::RunProgram() {
	int loc = 100;
	int opcode = 0;
	int address = 0;
	bool run = true;

	cout << "Emulation" << endl;

	if (Errors::ErrorSize() > 0) {
		cout << "There were errors compiling, emulation will not be run." << endl;
		return 0;
	}

	while (run) {
		ParseNum(loc, opcode, address);

		switch (opcode) {
		case 1:
			m_acc = m_acc + m_memory[address];
			loc++;
			break;

		case 2:
			m_acc = m_acc - m_memory[address];
			loc++;
			break;

		case 3:
			m_acc = m_acc * m_memory[address];
			loc++;
			break;

		case 4:
			m_acc = m_acc / m_memory[address];
			loc++;
			break;

		case 5:
			m_acc = m_memory[address];
			loc++;
			break;

		case 6:
			m_memory[address] = m_acc;
			loc++;
			break;

		case 7:
			cout << "?";
			cin >> m_memory[address];
			if (!cin) {
				cout << "Input was not an integer, terminated." << endl;
				return 0;
			}
			loc++;
			break;

		case 8:
			cout << m_memory[address] << endl;
			loc++;
			break;

		case 9:
			loc = address;
			break;

		case 10:
			if (m_acc < 0) {
				loc = address;
			}
			else {
				loc++;
			}
			break;

		case 11:
			if (m_acc == 0) {
				loc = address;
			}
			else {
				loc++;
			}
			break;

		case 12:
			if (m_acc > 0) {
				loc = address;
			}
			else {
				loc++;
			}
			break;

		case 13:
			run = false;
			break;

		default:
			run = false;
			break;
		}

	};

	return true;
};
/*bool Emulator::RunProgram() */