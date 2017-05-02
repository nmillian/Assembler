//
//		Class to parse and provide information about instructions
//		Public functions to ParseInstruction, LocationNextInstruction, and accessor functions.
//
#pragma once

// The elements of an instruction.
class Instruction {

public:

	// Instruction constructor
	Instruction() { };

	// Instruction destructor 
	~Instruction() { };

	// Codes to indicate the type of instruction we are processing. 
	enum InstructionType {
		ST_MachineLanguage, // A machine language instruction.
		ST_AssemblerInstr,  // Assembler Language instruction.
		ST_Comment,         // Comment or blank line
		ST_End              // end instruction.
	};

	// Parse the Instruction.
	InstructionType ParseInstruction(string &a_buff);

	// Compute the location of the next instruction.
	int LocationNextInstruction(int a_loc);

	// To access the label
	string GetLabel();

	// Access the OpCode
	string GetOpCode();

	// Access the Operand
	string GetOperand();

	// Access original instruction
	string OrgInstruct();

	// Access number of OpCode
	int GetNumOpCode();

	// Get operand value
	int GetOpValue();

	// Checks if it's an assem instruction
	bool IsAssem();

	// Checks if it's a machine instruction
	bool IsMachine();

	// Check if it's a comment
	bool IsComment();

	// Check if it's an end
	bool IsEnd();

	// Check if the operand is numeric
	bool IsNumericOP();

	// To determine if a label is blank.
	bool IsLabel();

	// Returns the number of words that were in a string.
	int GetSize();

private:
	// The elemements of a instruction
	string m_Label;        // The label.
	string m_OpCode;       // The symbolic op code.
	string m_Operand;      // The operand.

	string m_instruction;    // The original instruction.

	// Derived values.
	int m_NumOpCode;     // The numerical value of the op code.
	InstructionType m_type; // The type of instruction.

	bool m_IsNumericOperand;// == true if the operand is numeric.
	int m_OperandValue;   // The value of the operand if it is numeric.

	int m_Size; //The number of words read in from each line. 

	// Function to remove a comment from a line.
	void RemoveComment(string &a_buff);

	// Tokenize a string into words.
	void TokenizeString(string &a_buff, vector<string> &a_tokens);

	// Change stored OpCode to all the same case, lower case, as they are not case sensitive.
	void OpCodeToLower();

	// Set the m_NumOpCode to it's corresponding number.
	void SetNumOpCode();
};

