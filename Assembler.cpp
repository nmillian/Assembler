//
//      Implementation of the Assembler class.
//

#pragma once;

#include "stdafx.h"
#include "Assembler.h"
#include "Instruction.h"
#include "Emulator.h"
#include "Errors.h"

/**/
/*
NAME

Assembler::Assembler - Constructor for the assembler. Passing argc and argv to the file access constructor.

SYNOPSIS

Assembler::Assembler(int argc, char *argv[]): m_facc(argc, argv);
argc --> Which command line argument to use.
argv[] --> The name of the command line arguement. 
m_facc(argc, argv) --> Passing argc and argv to file access constructor

DESCRIPTION

This is the constructor for the assembler class. 
Passes argc and argv to the file access constructor.

RETURNS

It is a constructor, no returns.

AUTHOR

Nicole Millian

DATE

8:01pm 12/23/2015

*/
/**/
Assembler::Assembler(int argc, char *argv[]): m_facc(argc, argv){
	// Nothing else to do here.
}
/*Assembler::Assembler(int argc, char *argv[]): m_facc(argc, argv); */

/**/
/*
NAME

Assembler::~Assembler - Destructor for Assembler class.

SYNOPSIS

Assembler::~Assembler()
No arguments for this function, it's a destructor. 

DESCRIPTION

This is the destructor for the assembler class.

RETURNS

It is a destructor, no returns.

AUTHOR

Nicole Millian

DATE

8:16pm 12/23/2015

*/
/**/
Assembler::~Assembler(){
	// Placeholder if it needs to do something in the future.
}
/*Assembler::~Assembler(); */

/**/
/*
NAME

Assembler::DisplaySymbolTable - Makes a call to display the symbol table to the console.

SYNOPSIS

void Assembler::DisplaySymbolTable();
No arguments for this function.

DESCRIPTION

This function makes a call to m_symtab.DisplaySymbolTable().
The symbol table will be displayed to the console. 

RETURNS

The function is void, no returns. 

AUTHOR

Nicole Millian

DATE

8:21pm 12/23/2015

*/
/**/
void Assembler::DisplaySymbolTable() {
	m_symtab.DisplaySymbolTable();
}
/*void Assembler::DisplaySymbolTable(); */

/**/
/*
NAME

Assembler::RunProgramInEmulator - Makes a call to run the program in the emulator. 

SYNOPSIS

void Assembler::RunProgramInEmulator();
No arguments for this function.

DESCRIPTION

This function makes a call to m_emul.RunProgram().
The emulator is run in the console. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

8:29pm 12/23/2015

*/
/**/
void Assembler::RunProgramInEmulator() {
	m_emul.RunProgram();
}
/* void Assembler::RunProgramInEmulator(); */

/**/
/*
NAME

Assembler::PassI - Pass I establishes the location of the labels.

SYNOPSIS

void Assembler::PassI()
No arguments for this function.

DESCRIPTION

This function establishes the location of the labels by 
successively reading each line of source code from a file.
Each line, buff, is called with ParseInstruction, in order to parse each line into words
and establish labels. The InstructionType is returned from ParseInstruction. 
If the instruction has a label, the label is recorded in the symbol table.
The LocationNextInstruction() is called on loc to get the location of the next location.
The function ends when there are no more lines to read or an end statement is found. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

9:10pm 12/23/2015

*/
/**/
void Assembler::PassI(){
	int loc = 0;        // Tracks the location of the instructions to be generated.

	// Successively process each line of source code.
	for (;;) {
	
		// Read the next line from the source file.
		string buff;

		if (!m_facc.GetNextLine(buff)) {
			// If there are no more lines, we are missing an end statement.
			// We will let this error be reported by Pass II.
			return;
		}

		// Parse the line and get the instruction type.
		Instruction::InstructionType st = m_inst.ParseInstruction(buff);
		
		// If this is an end statement, there is nothing left to do in pass I.
		// Pass II will determine if the end is the last statement.
		if (st == Instruction::ST_End) return;

		// Labels can only be on machine language and assembler language
		// instructions.
		if (st != Instruction::ST_MachineLanguage && st != Instruction::ST_AssemblerInstr) {
			continue;
		}

		// If the instruction has a label, record it and its location in the
		// symbol table.
		if (m_inst.IsLabel()) {
			m_symtab.AddSymbol(m_inst.GetLabel(), loc);
		}

		// Compute the location of the next instruction.
		loc = m_inst.LocationNextInstruction(loc);

	}

	return;
}
/*void Assembler::PassI() */

/**/
/*
NAME

Assembler::CheckEndInst - Check if end is the last statement.

SYNOPSIS

void Assembler::CheckEndInst(vector<string>a_tokens)
a_tokens --> The vector of tokens to check if the end statement is last.

DESCRIPTION

This function checks if there is an end statement as the final word in the source file.
If the last word is not end, it throws an error string. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

9:19pm 12/23/2015

*/
/**/
void Assembler::CheckEndInst(vector<string>a_tokens) {
	string enderr = "Error with end statement";

	string last = a_tokens.at(a_tokens.size() - 1);
	if (last.compare("end") != 0) {
		throw enderr;
	}
}
/*void Assembler::CheckEndInst(vector<string>a_tokens)*/

/**/
/*
NAME

Assembler::LocSizeCheck  - Check if loc is a valid location.

SYNOPSIS

void Assembler::LocSizeCheck(int a_loc)
a_loc --> The location to check the size of.

DESCRIPTION

This function checks if loc is a valid location.
Loc is an invalid location if it is over 9999. 
If it is not a valid location, an error is thrown. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

9:29pm 12/23/2015

*/
/**/
void Assembler::LocSizeCheck(int a_loc) {
	string locerr = "Location invalid, there was an error. Setting Loc to 1.";

	if (a_loc > 9999) {
		throw locerr;
	}
}
/*void Assembler::LocSizeCheck(int a_loc);*/

/**/
/*
NAME

Assembler::CheckMachOpSize - Check the number of operands for a machine instruction.

SYNOPSIS

void Assembler::CheckMachOpSize(string a_OpCodeName);
a_OpCodeName--> The OpCodeName to check, there are certain size exceptions for some machine instructions.

DESCRIPTION

Checks the number of operands for a machine instruction.
If the number of operands is greater than 3, an error is thrown.
If the number of operands is less than 2 and the opcode name is not "halt" then an error is thrown.
If the number of operands is greater than 1 and the opcode name is "hatl" then an error is thrown.

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

9:34pm 12/23/2015

*/
/**/
void Assembler::CheckMachOpSize(string a_OpCodeName) {
	string numoperr = "Error with number of operands";

	if (m_inst.GetSize() > 3) {
		throw numoperr;
	}

	if (m_inst.GetSize() < 2 && a_OpCodeName.compare("halt") != 0) {
		throw numoperr;
	}

	if (m_inst.GetSize() > 1 && a_OpCodeName.compare("halt") == 0) {
		throw numoperr;
	}
}
/*void Assembler::CheckMachOpSize(string a_OpCodeName); */

/**/
/*
NAME

Assembler::MultiplyDefined - Check if a label is multiply defined.

SYNOPSIS

void Assembler::MultiplyDefined(int a_multiloc);
a_multiloc --> The location to check if multiply defined.

DESCRIPTION

This function checks to see if a label is multiply defined by checking it's location, multiloc.
If a_multiloc == -999, then an error is thrown as it's not a valid location.

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

9:39pm 12/23/2015

*/
/**/
void Assembler::MultiplyDefined(int a_multiloc) {
	string err = "Label defined more than once.";

	if (a_multiloc == -999) {
		throw err;
	}
}
/* void Assembler::MultiplyDefined(int a_multiloc); */

/**/
/*
NAME

Assembler::CheckLabelSizeChar - Check a label size and the first char.

SYNOPSIS

void Assembler::CheckLabelSizeChar(string a_label);
a_label --> The label to check the size and first character of.

DESCRIPTION

This function checks to see if a label is a correct size, under 10 chars, and
if the first character in the label is not a number. 
If the label is too big or the first character is a number then an error is thrown. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

9:45pm 12/23/2015

*/
/**/
void Assembler::CheckLabelSizeChar(string a_label) {
	string labelerr = "Label is invalid";

	//Check label size and first letter in label
	if (a_label.size() > 10 || !isalpha(a_label.at(0))) {
		throw labelerr;
	}

}
/* void Assembler::CheckLabelSizeChar(string a_label); */

/**/
/*
NAME

Assembler::CheckOperandLabel - Checks to see if an operand matches a label in the symbol table.

SYNOPSIS

void Assembler::CheckOperandLabel(bool a_check);
a_check --> Is either true or false, depending on if the operand was found in the symbol table.

DESCRIPTION

The function checks if a_check is true or false, which means the symbol was either in the symbol table or not.
It also checks if the operand does not equal NULL.
If the operand is not in the symbol table and does not equal NULL then an error is thrown. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

9:50pm 12/23/2015

*/
/**/
void Assembler::CheckOperandLabel(bool a_check) {
	string operanderr = "Operand does not match label";

	if (a_check == false && (m_inst.GetOperand() != "NULL")) {
		throw operanderr;
	}
}
/* void Assembler::CheckOperandLabel(bool a_check); */

/**/
/*
NAME

Assembler::CheckOperandSizeChar - Checks to see if the operand size is valid and if the first character in the operand is valid.

SYNOPSIS

void Assembler::CheckOperandSizeChar(string a_operand);
a_operand --> A string of the operand name to check for validity. 

DESCRIPTION

This function checks to see if an operand size and first character is valid.
If a_operand size is over 10 characters or the first character in a_operand is not a character,
then an error is thrown.

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

10:01pm 12/23/2015

*/
/**/
void Assembler::CheckOperandSizeChar(string a_operand) {
	string opnameerr = "Operand name is invalid";

	//Check operand size and first char of operand
	if (a_operand.size() > 10 || !isalpha(a_operand.at(0))) {
		throw opnameerr;
	}

}
/*void Assembler::CheckOperandSizeChar(string a_operand); */

/**/
/*
NAME

Assembler::CheckOpCode() - Checks to see if a NumOpCode is valid.

SYNOPSIS

void Assembler::CheckOpCode();
There are no arguments in this function.

DESCRIPTION

This function checks to see if a NumOpCode is valid.
If m_inst.GetNumOpCode() == -99, then there is an error and an error is thrown.

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

10:11pm 12/23/2015

*/
/**/
void Assembler::CheckOpCode() {
	string operr = "Illegal opcode, instruction is not vaild";

	if (m_inst.GetNumOpCode() == -99) {
		throw operr;
	}
}
/*void Assembler::CheckOpCode(); */

/**/
/*
NAME

Assembler::CheckSymbolic() - Checks to see if an operand is symbolic.

SYNOPSIS

void Assembler::CheckSymbolic();
There are no arguments in this function.

DESCRIPTION

This function checks to see if an operand is symbolic.
If m_inst.IsNumericOP() returns true, an error is thrown.

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

10:18pm 12/23/2015

*/
/**/
void Assembler::CheckSymbolic() {
	string nummachine = "Operand must be symbolic";

	if (m_inst.IsNumericOP()) {
		throw nummachine;
	}
}
/* void Assembler::CheckSymbolic(); */

/**/
/*
NAME

Assembler::CheckAssemOpSize - Checks the number of operands in an assembler instruction.

SYNOPSIS

void Assembler::CheckAssemOpSize(string a_OpCodeName);
a_OpCodeName --> The opcode name to check, some assem instructions can have a different number of operands.

DESCRIPTION

This function checks the number of operands in an assem instruction.
If the instruction is an org, then the size must be 2. If it is not an error is thrown.
If the instruction is a ds, the size must be 3. If it is not, an error is thrown.
An error is thrown if an instruction is bigger than 3 or less than equal to 2. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

10:23pm 12/23/2015

*/
/**/
void Assembler::CheckAssemOpSize(string a_OpCodeName) {
	string numoperr = "Error with number of operands";

	if (a_OpCodeName.find("org") != string::npos) {
		if (m_inst.GetSize() > 2 || m_inst.GetSize() <= 1) {
			throw numoperr;
		}
	}

	else if (a_OpCodeName.find("ds") != string::npos) {
		if (m_inst.GetSize() > 3 || m_inst.GetSize() <= 2) {
			throw numoperr;
		}
	}

	else {
		if (m_inst.GetSize() > 3 || m_inst.GetSize() <= 2) {
			throw numoperr;
		}
	}
}
/* void Assembler::CheckAssemOpSize(string a_opCodeName); */

/**/
/*
NAME

Assembler::CheckAssemInstr - Checks to see if an assembler instruction is a valid instruction.

SYNOPSIS

void Assembler::CheckAssemInstr(string a_OpCodeName);
a_OpCodeName --> The OpCodeName to check if it's valid.

DESCRIPTION

This function checks if an OpCodeName is a valid Assembler Instruction.
If the OpCodeName is not a "dc", "org", or a "ds", then it is invalid and an error is thrown. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

10:33pm 12/23/2015

*/
/**/
void Assembler::CheckAssemInstr(string a_OpCodeName) {
	string operr = "Illegal opcode, instruction is not vaild";

	if (a_OpCodeName.compare("dc") != 0 && a_OpCodeName.compare("org") != 0 && a_OpCodeName.compare("ds") != 0) {
		throw operr;
	}
}
/* void Assembler::CheckAssemInstr(string a_OpCodeName); */

/**/
/*
NAME

Assembler::CheckAssemOpValue() - Checks to see if an operand is a valid number for an assembler instruction.

SYNOPSIS

void Assembler::CheckAssemOpValue();
There are no arguements for this function.

DESCRIPTION

Checks to see if an assembler instruction has a legal numeric operand.
If the operand value is above 9999, then it is an illegal value and an error is thrown.

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

10:39pm 12/23/2015

*/
/**/
void Assembler::CheckAssemOpValue() {
	string numerr = "Illegal operand number, can't go over 9999";

	if (m_inst.GetOpValue() > 9999) {
		throw numerr;
	}
}
/* void Assembler::CheckAssemOpValue(); */


/**/
/*
NAME

Assembler::CheckEndOperands() - Check the number of operands for an end instruction.

SYNOPSIS

void Assembler::CheckEndOperands()
There are no arguments for this function.

DESCRIPTION

Checks the number of operands for an end instruction.
If the size of a line for an end instruction is not 1, then there is an error and an error is thrown.

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

10:46pm 12/23/2015

*/
/**/
void Assembler::CheckEndOperands() {
	string numoperr = "Error with number of operands"; 
	if (m_inst.GetSize() != 1) {
		throw numoperr;
	}
}
/* void Assembler::CheckEndOperands(); */

/**/
/*
NAME

Assembler::PassII() - Generate a translation.

SYNOPSIS

void Assembler::PassII();
There are no arguements for this function.

DESCRIPTION

Pass II generates a translation of the source text. The file is reset back to the beginning and is
run through line by line again. Pass II is where errors are reported to the console and also logged.
Pass II also loads contents into the emulator's memory.
Each line is parsed and each individual word is put into a vector of strings called tokens.
If the line is a Comment, it is printed to the console without any error checking.
If the line is a Machine Instruction, it is inserted into emulator memory, printed to console, and is checked for errors.
If the line is an Assembley Instruction, it is printed if it's an org or a ds, if it's a dc it's inserted
into the emulator and printed to the console. All Assembley Instructions are checked for errors.
If the line is an End Instruction, it is printed to the console and checked for errors. 
This process continues untill the end of file is found. 

RETURNS

The function is void, no returns.

AUTHOR

Nicole Millian

DATE

11:12pm 12/23/2015

*/
/**/
void Assembler::PassII() {

	// Reset the file back to the beginning.
	m_facc.Rewind();

	// Initialize error reporting
	Errors::InitErrorReporting();

	// Tracks the location of the instructions to be generated.
	int loc = 0;        

	// Vector of strings to hold each word from file.
	vector<string> tokens;

	cout << endl;
	cout << "Location" << setw(10) << "Contents" << setw(20) << "Original Statement" << endl;
	
	// Successively process each line of source code.
	for (;;) {
		
		// Read the next line from the source file.
		string buff;

		if (!m_facc.GetNextLine(buff)) {
			// Check to see that end was the last input
			try {
				CheckEndInst(tokens);
			}
			catch(string e){
				Errors::RecordError(e);
				cout << left << setfill(' ') << setw(20) << " " << e << endl;
				cout << endl;
			}

			return;
		}

		// Parse the line and get the instruction type.
		Instruction::InstructionType st = m_inst.ParseInstruction(buff);

		// Change the string to lowercase.
		for (unsigned int i = 0; i < buff.length(); i++) {
			buff[i] = tolower(buff[i]);
		}

		// If there's a comment in the instruction and if there is remove it
		if (buff.find(";") != string::npos) {
			string commentline = buff.substr(buff.find(";"));
			buff.erase(buff.find(";"));
		}
		
		// Reads in each word one by one and puts it into vector<string> tokens;
		istringstream iss(buff);
		string word;
		while (iss >> word) {
			tokens.push_back(word);
		}

		// Check if loc is too big.
		try {
			LocSizeCheck(loc);
		}
		catch(string e){
			Errors::RecordError(e);
			cout << left << e << endl;
			cout << endl;
			loc = 1;
		}

		// Print out loc to console
		if (!m_inst.IsComment() && !m_inst.IsEnd() ){
			cout << left << setw(10) << loc;
		}

		// Variable to hold the contents to be inserted.
		int contents = 0;

		// Variable to hold the symbol location.
		int symloc = 0;

		// Variable to hold the symbol location when checking for multiple label declarations.
		int multiloc = 0;

		// Variable to hold the location of an operand if it is ound in the symbol table. 
		int operandloc = 0;

		// If the instruction was machine language.
		if (m_inst.IsMachine()){
			
			// Get the OpCode name.
			string opCodeName = m_inst.GetOpCode();

			// Look symbol in the symbol table to get it's location, stored in symloc.
			m_symtab.LookupSymbol(m_inst.GetOperand(), symloc);

			// Contents is NumOpCode * 10,000 + symloc .
			contents = (m_inst.GetNumOpCode() * 10000) + symloc;

			// Insert the contents into memory at the location of loc.
			m_emul.InsertMemory(loc, contents);

			// Print contents to the console.
			cout << internal << setfill('0') << setw(6) << contents;

			// Print original instruction to the console. 
			cout << left << setfill(' ') << setw(5) << " " << m_inst.OrgInstruct() << endl;

			// Check the number of operands in a line.
			try {
				CheckMachOpSize(opCodeName);
			}
			catch (string e) {
				Errors::RecordError(e);
				cout << left << setfill(' ') << setw(20) << " " << e << endl;
				cout << endl;
			}

			//Label Checking, check if there is a label 
			if (m_inst.IsLabel()) {
				// Get the label
				string label = m_inst.GetLabel();
				
				// Lookup the label in the symbol tabel and multiloc will be set to it's location
				m_symtab.LookupSymbol(m_inst.GetLabel(), multiloc);

				//Check for multiple defined labels
				try {
					MultiplyDefined(multiloc);
				}
				catch (string e) {
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}
				
				//Check label size & the first letter in the label
				try {
					CheckLabelSizeChar(label);
				}
				catch(string e){
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}
				
			}

			//Check for operands that are not defined.
			//Check if the operand is not numeric
			if ( !m_inst.IsNumericOP()) { 
				// Get the operand
				string operand = m_inst.GetOperand();

				// Check if the operand is in the symbol tabel, if it is operandloc is set to the location.
				bool check = m_symtab.LookupSymbol(m_inst.GetOperand(), operandloc);

				// Check to see if operand matches a label
				try {
					CheckOperandLabel(check);
				}
				catch(string e){
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}

				// Check the operand size and first letter in operand
				try {
					CheckOperandSizeChar(operand);
				}
				catch (string e) {
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}

			}

			// Make sure operands are symbolic
			try {
				CheckSymbolic();
			}
			catch (string e) {
				Errors::RecordError(e);
				cout << left << setfill(' ') << setw(20) << " " << e << endl;
				cout << endl;
			}

			// Check for illegal opcode
			try {
				CheckOpCode();
			}
			catch (string e) {
				Errors::RecordError(e);
				cout << left << setfill(' ') << setw(20) << " " << e << endl;
				cout << endl;
			}
		
		}
		
		
		// The instruction is assembley language
		else if (m_inst.IsAssem()){
			string opCodeName = m_inst.GetOpCode();

			// Print out org
			if (opCodeName.find("org") != string::npos) {
				cout << left << setfill(' ') << setw(10) << " " << m_inst.OrgInstruct() << endl;
			}

			// Print out ds.
			else if (opCodeName.find("ds") != string::npos) {
				cout << left << setfill(' ') << setw(11) << " " << m_inst.OrgInstruct() << endl;
			}

			// Print out dc
			else {
				//Insert dc into memory as it is a constant.
				m_emul.InsertMemory(loc, m_inst.GetOpValue());
				cout << internal << setfill('0') << setw(6) << m_inst.GetOpValue();
				cout << left << setfill(' ') << setw(5) << " ";
				cout << m_inst.OrgInstruct() << endl;
			}

			// See if operands are valid.
			try {
				CheckAssemOpSize(opCodeName);
			}
			catch(string e){
				Errors::RecordError(e);
				cout << left << setfill(' ') << setw(20) << " " << e << endl;
				cout << endl;
			}
			
			//Label Checking.
			if (m_inst.IsLabel()) {

				// Get the label
				string label = m_inst.GetLabel();

				// Lookup the label in the symbol tabel and multiloc will be set to it's location
				m_symtab.LookupSymbol(m_inst.GetLabel(), multiloc);

				//Check for multiple defined labels
				try {
					MultiplyDefined(multiloc);
				}
				catch (string e) {
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}

				//Check label size & the first letter in the label
				try {
					CheckLabelSizeChar(label);
				}
				catch (string e) {
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}
			}

			//Check for operands that are not defined.
			if (!m_inst.IsNumericOP()) { //if it is not numeric
				string operand = m_inst.GetOperand();

				//If it's not numeric for assembler instruc, it's an error. 
				string numassem = "Operand must be numeric";
				Errors::RecordError(numassem);
				cout << endl;
				cout << left << setfill(' ') << setw(20) << " " << numassem << endl;

				//Check if operand is in sym table
				bool check = m_symtab.LookupSymbol(m_inst.GetOperand(), operandloc);

				// Check to see if operand matches a label
				try {
					CheckOperandLabel(check);
				}
				catch (string e) {
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}

				// Check the operand size and first letter in operand
				try {
					CheckOperandSizeChar(operand);
				}
				catch (string e) {
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}
			}

			//Check for illegal operand numbers
			if (m_inst.IsNumericOP()) {
				//Check for illegal number
				try {
					CheckAssemOpValue();
				}
				catch(string e){
					Errors::RecordError(e);
					cout << left << setfill(' ') << setw(20) << " " << e << endl;
					cout << endl;
				}
				
			}

			//Check for illegal assem instructions
			try {
				CheckAssemInstr(opCodeName);
			}
			catch (string e) {
				Errors::RecordError(e);
				cout << left << setfill(' ') << setw(20) << " " << e << endl;
				cout << endl;
			}

			
		}

		// This is an end statement.
		else if (m_inst.IsEnd()){
			// Print out original statement.
			cout << left << setfill(' ') << setw(21) << " " << m_inst.OrgInstruct()  << endl;

			// Check the number of operands.
			try {
				CheckEndOperands();
			}
			catch (string e) {
				Errors::RecordError(e);
				cout << left << setfill(' ') << setw(20) << " " << e << endl;
				cout << endl;
			}
		}
		
		// This is a comment in the file.
		else {
			cout << left << setfill(' ') << setw(21) << " " << m_inst.OrgInstruct() << endl;
		}


		// Compute the location of the next instruction.
		loc = m_inst.LocationNextInstruction(loc);

	}

	return;
}
/* void Assembler::PassII() */