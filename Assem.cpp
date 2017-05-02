/*
 Assembler main program.
*/
#include "stdafx.h"     // This must be present if you use precompiled headers which you will use.
#include <stdio.h>

#include "Assembler.h"

int main(int argc, char *argv[]){
	
	Assembler assem(argc, argv);

	// Establish the location of the labels:
	assem.PassI();

	// Display the symbol table.
	assem.DisplaySymbolTable();

	// Translate and output
	assem.PassII();

	// Run the emulator on the VC3600 program that came from the translation.
	// The emulation does not run if there are errors found in Pass II.
	assem.RunProgramInEmulator();

	// Terminate indicating all is well.

	return 0;
}