#include "stdafx.h"
#include "Errors.h"

// Initialize the vector of strings. 
vector<string> Errors::m_ErrorMsgs;

/**/
/*
NAME

Errors::InitErrorReporting - Initialize error reporting.

SYNOPSIS

void Errors::InitErrorReporting()
No arguments are passed to the function.

DESCRIPTION

This function will clear out any previous errors stored in m_ErrorMsgs.

RETURNS

No returns, the funtion is void.

AUTHOR

Nicole Millian

DATE

10:24pm 12/19/2015
*/
/**/
void Errors::InitErrorReporting() {
	m_ErrorMsgs.clear();
};
/*void Errors::InitErrorReporting()*/

/**/
/*
NAME

Errors::RecordError - Records an error in a vector of strings called m_ErrorMsgs.

SYNOPSIS

void Errors::RecordError(const string &a_mesg);
a_mesg -> The error string to be recorded.

DESCRIPTION

This function will record an error, a_mesg, in the vector of strings, m_ErrorMsgs. 

RETURNS

No returns, the funtion is void.

AUTHOR

Nicole Millian

DATE

10:55pm 12/19/2015
*/
/**/
void Errors::RecordError(const string &a_mesg) {
	m_ErrorMsgs.push_back(a_mesg);
};
/*void Errors::RecordError(const string &a_mesg);*/

/**/
/*
NAME

Errors::DisplayErrors - Display the errors which have been recorded in m_ErrorMsgs.

SYNOPSIS

void Errors::DisplayErrors();
No arguments are passed to the function.

DESCRIPTION

This function will loop through the vector m_ErrorMsgs and display any errors
which have been recorded to the console.

RETURNS

No returns, the funtion is void.

AUTHOR

Nicole Millian

DATE

11:01pm 12/19/2015
*/
/**/
void Errors::DisplayErrors() {
	for (int i = 0; i < m_ErrorMsgs.size(); i++) {
		cout << m_ErrorMsgs.at(i) << endl;
	}
};
/*void Errors::DisplayErrors();*/

/**/
/*
NAME

Errors::ErrorSize - Return the amount of errors which have been recorded.

SYNOPSIS

int Errors::ErrorSize();
No arguments are passed to the function.

DESCRIPTION

This function will return the size of the vector m_ErrorMsgs, which is
the number of errors which have been recorded.

RETURNS

Returns an int, which is the size of the vector m_ErrorMsgs.

AUTHOR

Nicole Millian

DATE

11:10pm 12/19/2015
*/
/**/
int Errors::ErrorSize() {
	return m_ErrorMsgs.size();
};
/*int Errors::ErrorSize();*/