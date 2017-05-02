//
//		Emulator class - supports the emulation of VC3600 programs
//		Has public functions to InsertMemory, ParseNum, and RunProgram()
//
#ifndef _Emulator_H      // UNIX way of preventing multiple inclusions.
#define _Emulator_H

class Emulator {

public:

	const static int MEMSZ = 10000;	// The size of the memory of the VC3600.

	// The default Emulator constructor 
	Emulator() {
		memset(m_memory, 0, MEMSZ * sizeof(int));
	}

	// Records instructions and data into VC3600 memory.
	bool InsertMemory(int a_location, int a_contents);

	// Parses the contents into an opcode and an address.
	void ParseNum(int a_loc, int&a_opcode, int&a_address);

	// Runs the VC3600 program recorded in memory.
	bool RunProgram();

private:

	// The memory of the VC3600.
	int m_memory[MEMSZ];

	// The accumulator of the VC3600.
	int m_acc;

	// The count of the number of items inserted into memory.
	int count = 0;
};

#endif
