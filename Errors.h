//
// Class to manage error reporting. Note: all members are static so we can access them anywhere.
// Has public functions, InitErrorReporting, RecordError, DisplayError, and ErrorSize.
//
#pragma once

using namespace std;

class Errors {

public:

	// Initializes error reports.
	static void InitErrorReporting();

	// Records an error message.
	static void RecordError(const string &a_mesg);

	// Displays the collected error message.
	static void DisplayErrors();

	// Returns how many errors were reported.
	static int ErrorSize();

private:

	static vector<string> m_ErrorMsgs;
};
