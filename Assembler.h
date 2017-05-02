//
//		Assembler class.  This is a container for all the components
//		that make up the assembler.
//		Has public functions to DisplaySymbolTable, RunProgramInEmulator, PassI, and PassII.
//	
#pragma once 

#include "SymTab.h"
#include "Instruction.h"
#include "FileAccess.h"
#include "Emulator.h"

using namespace std;

class Assembler {

public:
	// Constructor for Assembler class.
	Assembler(int argc, char *argv[]);

	// Destructor for Assembler class.
	~Assembler();

	// Display the symbols in the symbol table.
	void DisplaySymbolTable();

	// Run emulator on the translation.
	void RunProgramInEmulator();

	// Pass I - establish the locations of the symbols.
	void PassI();

	// Pass II - generate a translation and error reporting.
	void PassII();

private:

	FileAccess m_facc;	    // File Access object
	SymbolTable m_symtab;	// Symbol table object
	Instruction m_inst;	    // Instruction object
	Emulator m_emul;        // Emulator for VC3600


	//Private functions used for error checking in Pass II

	// Check if end is the last statement in the source file.
	void CheckEndInst(vector<string>a_tokens);

	// Check if loc is a valid location.
	void LocSizeCheck(int a_loc);

	// Check the number of operands for a machine instruction.
	void CheckMachOpSize(string a_opCodeName);

	// Check if a label is multiply defined.
	void MultiplyDefined(int a_multiloc);

	// Check a label size and the first char.
	void CheckLabelSizeChar(string a_label);

	// Checks to see if an operand matches a label in the symbol table.
	void CheckOperandLabel(bool a_check);

	// Checks to see if the operand size is valid and if the first character in the operand is valid.
	void CheckOperandSizeChar(string a_operand);

	// Checks to see if a NumOpCode is valid.
	void CheckOpCode();

	// Checks to see if an operand is symbolic.
	void CheckSymbolic();

	// Checks the number of operands in an assembler instruction.
	void CheckAssemOpSize(string a_opCodeName);

	// Checks to see if an assembler instruction is a valid instruction.
	void CheckAssemInstr(string a_opCodeName);

	// Checks to see if an operand is a valid number for an assembler instruction.
	void CheckAssemOpValue();

	// Check the number of operands for an end instruction.
	void CheckEndOperands();
};
