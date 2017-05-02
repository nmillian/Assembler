#include "stdafx.h"
#include "Instruction.h"

/**/
/*
NAME

Instruction::GetLabel - Get value of the Instruction class variable m_Label.

SYNOPSIS

string Instruction::GetLabel();
No arguments are passed to the function.

DESCRIPTION

Gets the m_Label string, a private variable of the Instruction class. 

RETURNS

The function returns the string m_Label.

AUTHOR

Nicole Millian

DATE

10:51pm 12/20/2015

*/
/**/
string Instruction::GetLabel() {
	return m_Label;
}
/* string Instruction::GetLabel() */

/**/
/*
NAME

Instruction::GetOpCode  - Get value of the Instruction class variable m_OpCode.

SYNOPSIS

string Instruction::GetOpCode();
No arguments are passed to the function.

DESCRIPTION

Gets the m_OpCode string, a private variable of the Instruction class.

RETURNS

The function returns the string m_OpCode.

AUTHOR

Nicole Millian

DATE

10:56pm 12/20/2015

*/
/**/
string Instruction::GetOpCode() {
	return m_OpCode;
}
/* string Instruction::GetOpCode() */

/**/
/*
NAME

Instruction::GetOperand  - Get value of the Instruction class variable m_Operand.

SYNOPSIS

string Instruction::GetOperand();
No arguments are passed to the function.

DESCRIPTION

Gets the m_Operand string, a private variable of the Instruction class.

RETURNS

The function returns the string m_Operand.

AUTHOR

Nicole Millian

DATE

11:02pm 12/20/2015

*/
/**/
string Instruction::GetOperand() {
	return m_Operand;
}
/* string Instruction::GetOperand() */

/**/
/*
NAME

Instruction::OrgInstruct  - Get value of the Instruction class variable m_instruction.

SYNOPSIS

string Instruction::OrgInstruct();
No arguments are passed to the function.

DESCRIPTION

Gets the m_instruction string, a private variable of the Instruction class.

RETURNS

The function returns the string m_instruction.

AUTHOR

Nicole Millian

DATE

11:07pm 12/20/2015

*/
/**/
string Instruction::OrgInstruct() {
	return m_instruction;
}
/* string Instruction::OrgInstruct() */

/**/
/*
NAME

Instruction::GetNumOpCode - Get value of the Instruction class variable m_NumOpCode.

SYNOPSIS

int Instruction::GetNumOpCode();
No arguments are passed to the function.

DESCRIPTION

Gets the m_NumOpCode string, a private variable of the Instruction class.

RETURNS

The function returns the strin m_NumOpCode.

AUTHOR

Nicole Millian

DATE

11:11pm 12/20/2015

*/
/**/
int Instruction::GetNumOpCode() {
	return m_NumOpCode;
}
/* int Instruction::GetNumOpCode() */

/**/
/*
NAME

Instruction::GetOpValue - Get value of the Instruction class variable  m_OperandValue.

SYNOPSIS

int Instruction::GetOpValue();
No arguments are passed to the function.

DESCRIPTION

Gets the  m_OperandValue string, a private variable of the Instruction class.

RETURNS

The function returns the strin  m_OperandValue.

AUTHOR

Nicole Millian

DATE

11:15pm 12/20/2015

*/
/**/
int Instruction::GetOpValue() {
	return m_OperandValue;
}
/* int Instruction::GetOpValue() */

/**/
/*
NAME

Instruction::IsAssem - Returns true or false if the instruction is an Assembler instruction.

SYNOPSIS

bool Instruction::IsAssem();
No arguments are passed to the function.

DESCRIPTION

Checks if m_type is ST_AssemblerInstr.

RETURNS

Returns true if m_type if ST_AssemblerInstr.
Returns false if m_type is not ST_AssemblerInstr.

AUTHOR

Nicole Millian

DATE

11:15pm 12/20/2015

*/
/**/
bool Instruction::IsAssem() {
	if (m_type == ST_AssemblerInstr) {
		return true;
	}
	else {
		return false;
	}
}
/* bool Instruction::IsAssem() */

/**/
/*
NAME

Instruction::IsMachine - Returns true or false if the instruction is a Machine Instruction.

SYNOPSIS

bool Instruction::IsMachine();
No arguments are passed to the function.

DESCRIPTION

Checks if m_type is  ST_MachineLanguage.

RETURNS

Returns true if m_type if  ST_MachineLanguage.
Returns false if m_type is not  ST_MachineLanguage.

AUTHOR

Nicole Millian

DATE

11:20pm 12/20/2015

*/
/**/
bool Instruction::IsMachine() {
	if (m_type == ST_MachineLanguage) {
		return true;
	}
	else {
		return false;
	}
}
/* bool Instruction::IsMachine() */

/**/
/*
NAME

Instruction::IsComment - Returns true or false if the instruction is a comment or not.

SYNOPSIS

bool Instruction::IsComment();
No arguments are passed to the function.

DESCRIPTION

Checks if m_type is  ST_Comment.

RETURNS

Returns true if m_type if  ST_Comment.
Returns false if m_type is not  ST_Comment.

AUTHOR

Nicole Millian

DATE

11:24pm 12/20/2015

*/
/**/
bool Instruction::IsComment() {
	if (m_type == ST_Comment) {
		return true;
	}
	else {
		return false;
	}
}
/* bool Instruction::IsComment()  */

/**/
/*
NAME

Instruction::IsEnd - Returns true or false if the instruction an end instruction or not.

SYNOPSIS

bool Instruction::IsEnd();
No arguments are passed to the function.

DESCRIPTION

Checks if m_type is  ST_End.

RETURNS

Returns true if m_type if  ST_End.
Returns false if m_type is not  ST_End.

AUTHOR

Nicole Millian

DATE

11:32pm 12/20/2015

*/
/**/
bool Instruction::IsEnd() {
	if (m_type == ST_End) {
		return true;
	}
	else {
		return false;
	}
}
/* bool Instruction::IsEnd() */

/**/
/*
NAME

Instruction::IsNumericOP - Returns true or false if the operand is numeric or not.

SYNOPSIS

bool Instruction::IsNumericOP();
No arguments are passed to the function.

DESCRIPTION

Gets the m_IsNumericOperand boolean value.

RETURNS

Returns the boolean value in m_IsNumericOperand.

AUTHOR

Nicole Millian

DATE

11:41pm 12/20/2015

*/
/**/
bool Instruction::IsNumericOP() {
	return m_IsNumericOperand;
}
/* bool Instruction::IsNumericOP() */

/**/
/*
NAME

Instruction:: IsLabel - Returns true or false if there is a label.

SYNOPSIS

bool Instruction:: IsLabel();
No arguments are passed to the function.

DESCRIPTION

Checks to see if it finds NULL in m_Label. If it's NULL there is no label, otherwise
there is a label. 

RETURNS

Returns false if NULL is in the label.
Returns true if there is a label.

AUTHOR

Nicole Millian

DATE

11:48pm 12/23/2015

*/
/**/
bool Instruction:: IsLabel() {
	if (m_Label.find("NULL") != string::npos) {
		return false;
	}

	else {
		return true;
	}
}
/* bool Instruction:: IsLabel() */

/**/
/*
NAME

Instruction::GetSize - Returns an int with the number of words in a line. 

SYNOPSIS

int Instruction::GetSize();
No arguments are passed to the function.

DESCRIPTION

Gets the value of m_Size, which is the number of words found in a line.

RETURNS

Returns an int, m_Size.

AUTHOR

Nicole Millian

DATE

11:55pm 12/20/2015

*/
/**/
int Instruction::GetSize() {
	return m_Size;
}
/* int Instruction::GetSize() */

/**/
/*
NAME

Instruction::LocationNextInstruction - Determines the location of the next instruction.

SYNOPSIS

int Instruction::LocationNextInstruction(int a_loc);
a_loc --> The current location, which is the location to bee updated.

DESCRIPTION

This function will determine where the location for the next instruction will be.
If it's a Machine Language instruction 1 is added to a_loc.
If it's an AssemblerInst, for ds and org the m_OperandValue is added to a_loc, for dc 1 is added to a_loc.
If it's a Comment or End statement then then a_loc is just returned.

RETURNS

The function returns an int, which is the updated a_loc.

AUTHOR

Nicole Millian

DATE

5:34pm 12/20/2015
*/
/**/
int Instruction::LocationNextInstruction(int a_loc) {
	if (m_type == ST_MachineLanguage) {
		return a_loc + 1;
	}

	else if (m_type == ST_AssemblerInstr) {
		if (m_OpCode.find("ds") != string::npos) {
			return a_loc + m_OperandValue;
		}

		else if (m_OpCode.find("dc") != string::npos) {
			return  a_loc + 1;
		}

		else if (m_OpCode.find("org") != string::npos) {
			return a_loc + m_OperandValue;
		}
	}

	else {
		return a_loc;
	}
}
/*int Instruction::LocationNextInstruction(int a_loc);*/

/**/
/*
NAME

Instruction::RemoveComment - Removes a comment from the string a_buff.

SYNOPSIS

void Instruction::RemoveComment(string &a_buff);
a_buff --> The string to remove a comment from.

DESCRIPTION

This function will determine if there is a comment in a_buff.
If there is a comment then it is removed from a_buff.
The string is passed by reference so a_buff will be updated.

RETURNS

The function is void, it does not return a value. 

AUTHOR

Nicole Millian

DATE

5:45pm 12/20/2015
*/
/**/
void Instruction::RemoveComment(string &a_buff) {
	if (a_buff.find(";") != string::npos) {
		string commentline = a_buff.substr(a_buff.find(";"));
		a_buff.erase(a_buff.find(";"));
	}
}
/*void Instruction::RemoveComment(string &a_buff);*/

/**/
/*
NAME

Instruction::TokenizeString - Tokenizes a string into words and stores them in a vector of strings.

SYNOPSIS

void Instruction::TokenizeString(string &a_buff, vector<string> &a_tokens);
a_buff --> The string to tokenize.
a_tokens --> The vector of strings to store each word separately.

DESCRIPTION

This function will go through a string, a_buff, and tokenize it.
Each word in the string is stored separately in the vector a_tokens. 
a_tokens is passed by reference so it can be updated with the tokens.

RETURNS

The function is void, it does not return a value.

AUTHOR

Nicole Millian

DATE

5:55pm 12/20/2015
*/
/**/
void Instruction::TokenizeString(string &a_buff, vector<string> &a_tokens) {
	// Reads in each word one by one and puts it into vector<string> tokens;
	istringstream iss(a_buff);
	string word;
	while (iss >> word) {
		a_tokens.push_back(word);
	}
}
/*void Instruction::TokenizeString(string &a_buff, vector<string> &a_tokens);*/

/**/
/*
NAME

Instruction::OpCodeToLower - Changes OpCode to all lowercase for parsing purposes, as they are not case sensitive.

SYNOPSIS

void Instruction::OpCodeToLower();
There are no arguments passed to this function.

DESCRIPTION

This function will go through a string, m_OpCode, and make all letters lowercase.
OpCodes are not case sensitive, so users can input them using any combination of upper and lowercase letters.
Making OpCodes all lowercase was a design choice for parsing purposes. 

RETURNS

The function is void, it does not return a value.

AUTHOR

Nicole Millian

DATE

6:34pm 12/20/2015
*/
/**/
void Instruction::OpCodeToLower() {
	// Make opcodes all lower case since it's not case sensitive
	for (string::size_type i = 0; i < m_OpCode.length(); ++i) {
		m_OpCode[i] = tolower(m_OpCode[i]);
	}
}
/*void Instruction::OpCodeToLower();*/

/**/
/*
NAME

Instruction::SetNumOpCode - Sets the m_NumOpCode to the corresponding number representing the machine instruction.

SYNOPSIS

void Instruction::SetNumOpCode();
There are no arguments passed to this function.

DESCRIPTION

This function set m_NumOpCode to a numeric value, depending on which machine instruction it was.
If the machine instruction does not have a matching numeric opcode, then the opcode value is set to -99.
"add" - m_NumOpCode = 1;

"sub" - m_NumOpCode = 2;

"mult" - m_NumOpCode = 3;

"div" - m_NumOpCode = 4;

"load" - m_NumOpCode = 5;

"store" - m_NumOpCode = 6;

"read" - m_NumOpCode = 7;

"write" - m_NumOpCode = 8;

"b" - m_NumOpCode = 9;

"bm" - m_NumOpCode = 10;

"bz" - m_NumOpCode = 11;

"bp" - m_NumOpCode = 12;

"halt" - m_NumOpCode = 13;

No mactching machine instr - m_NumOpCode = -99;

RETURNS

The function is void, it does not return a value.

AUTHOR

Nicole Millian

DATE

7:01pm 12/20/2015
*/
/**/
void Instruction::SetNumOpCode() {
	if (m_OpCode.compare("add") == 0) {
		m_NumOpCode = 1;
	}
	else if (m_OpCode.compare("sub") == 0) {
		m_NumOpCode = 2;
	}
	else if (m_OpCode.compare("mult") == 0) {
		m_NumOpCode = 3;
	}
	else if (m_OpCode.compare("div") == 0) {
		m_NumOpCode = 4;
	}
	else if (m_OpCode.compare("load") == 0) {
		m_NumOpCode = 5;
	}
	else if (m_OpCode.compare("store") == 0) {
		m_NumOpCode = 6;
	}
	else if (m_OpCode.compare("read") == 0) {
		m_NumOpCode = 7;
	}
	else if (m_OpCode.compare("write") == 0) {
		m_NumOpCode = 8;
	}
	else if (m_OpCode.compare("b") == 0) {
		m_NumOpCode = 9;
	}
	else if (m_OpCode.compare("bm") == 0) {
		m_NumOpCode = 10;
	}
	else if (m_OpCode.compare("bz") == 0) {
		m_NumOpCode = 11;
	}
	else if (m_OpCode.compare("bp") == 0) {
		m_NumOpCode = 12;
	}
	else if (m_OpCode.compare("halt") == 0) {
		m_NumOpCode = 13;
	}
	else {
		m_NumOpCode = -99;
	}
}
/*void Instruction::SetNumOpCode();*/

/**/
/*
NAME

InstructionType Instruction::ParseInstruction - Parses a string, a_buff, and assigns values to an instruction object.

SYNOPSIS

Instruction::InstructionType Instruction::ParseInstruction(string &a_buff)
a_buff --> The string to parse into instructions.

DESCRIPTION

This function will go through a string, a_buff, and parse it into instructions.
m_instruction is set to the original string, a_buff.
RemoveComment() is called on a_buff to remove comments from a_buff.
TokenizeString() is called on a_buff, and a_buff is tokenized into words which are stored in vector<string>tokens.
m_Size is set to the size of tokens.
Depending on m_Size, m_Label, m_OpCode, and m_Operand are set to values stored in the vector tokens.
If the vector has no tokens, m_type is set to ST_Comment, and is returned.
OpCodeToLower() is called to make m_OpCode lower case.
m_IsNumericOperand is set to true or false, depending on if an operand is numeric.
If m_IsNumericOperand is true, the value of m_OperandValue is set to the numeric value.
m_OpCode is compared to possible Machince instructions, if one is found m_type is set to ST_MachineLanguage and is returned.
m_OpCode is compared to possible Assem instructions, if one is found m_type is set to ST_AssemblerInst and is returned.
m_OpCode is compared to an End statement, if found m_type is set to ST_End and is returned.

RETURNS

The function returns the instruction type.
ST_MachineLanguage, // A machine language instruction.
ST_AssemblerInstr,  // Assembler Language instruction.
ST_Comment,         // Comment or blank line
ST_End              // end instruction

AUTHOR

Nicole Millian

DATE

7:38pm 12/21/2015
*/
/**/
Instruction::InstructionType Instruction::ParseInstruction(string &a_buff) {
	// Set m_instruction to the original instruction passed in.
	m_instruction = a_buff;
	
	// Default value to be assigned.
	string noval = "NULL";

	// Check if there's a comment in the instruction and if there is remove it
	RemoveComment(a_buff);

	// A vector of tokens, which is each separte word in a string.
	vector<string>tokens;

	// Break the string into words.
	TokenizeString(a_buff, tokens);

	// Get how many tokens are in the vector. 
	int tokenSize = tokens.size();

	// Set size equal to tokenSize
	m_Size = tokenSize;

	// If there are three tokens, there is a label, code, and operand.
	if (tokenSize == 3) {
		m_Label = tokens[0];
		m_OpCode = tokens[1];
		m_Operand = tokens[2];
	}

	// If there are two tokens, there should be no label, an op code, and operand.
	else if (tokenSize == 2) {
		m_Label = noval;
		m_OpCode = tokens[0];
		m_Operand = tokens[1];
	}

	// If there is a single token, should just be an opcode.
	else if (tokenSize == 1) {
		m_Label = noval;
		m_OpCode = tokens[0];
		m_Operand = noval;
	}

	// If there are more than four tokens, there is an error, don't set anything.
	else if (tokenSize > 4) {
		m_Label = noval;
		m_OpCode = noval;
		m_Operand = noval;
	}

	// There were no tokens, so it must have been a comment.
	// If it is a comment, there is no need to go any farther, return comment. 
	else {
		m_Label = noval;
		m_OpCode = noval;
		m_Operand = noval;
		m_NumOpCode = 0;
		m_type = ST_Comment;
		return ST_Comment;
	}

	// Make opcodes all lower case, as they are not case sensitive.
	OpCodeToLower();

	// Set the m_NumOpCode
	SetNumOpCode();
	
	// Check to see if the m_Operand is numeric and set the m_IsNumericOperand to true or false.
	bool has_only_digits = (m_Operand.find_first_not_of("0123456789") == string::npos);
	m_IsNumericOperand = has_only_digits;

	// If the m_IsNumericOperand is numeric, store it in m_Operand value.
	if (m_IsNumericOperand == true) {
		stringstream ss;
		ss << m_Operand;
		ss >> m_OperandValue;
	}

	// Check to see if the OpCode is Assem instruction, return if it is.
	if (m_OpCode.compare("dc") == 0 || m_OpCode.compare("ds") == 0 || m_OpCode.compare("org") == 0) {
		m_type = ST_AssemblerInstr;
		return ST_AssemblerInstr;
	}

	// Check to see if the OpCode is Machine instruction, return if it is.
	else if (m_OpCode.compare("add") == 0 || m_OpCode.compare("sub") == 0 || m_OpCode.compare("mult") == 0 ||
		m_OpCode.compare("div") == 0 || m_OpCode.compare("load") == 0 || m_OpCode.compare("store") == 0 ||
		m_OpCode.compare("read") == 0 || m_OpCode.compare("write") == 0 || m_OpCode.compare("b") == 0 || m_OpCode.compare("bm") == 0 ||
		m_OpCode.compare("bz") == 0 || m_OpCode.compare("bp") == 0 || m_OpCode.compare("halt") == 0) {

		m_type = ST_MachineLanguage;
		return ST_MachineLanguage;
	}

	// Check to see if the OpCode is End instruction, return if it is.
	else if (m_OpCode.compare("end") == 0) {
		m_type = ST_End;
		return ST_End;
	}
}
/*Instruction::InstructionType Instruction::ParseInstruction(string &a_buff);*/