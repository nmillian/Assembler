//
//  Implementation of file access class.
//
#include "stdafx.h"
#include "FileAccess.h"
#include <fstream>
#include <istream>

/**/
/*
NAME

FileAccess::FileAccess - Reads in file given from command line

SYNOPSIS

FileAccess::FileAccess(int a_argc, char *a_argv[]);
a_argc --> The amount of arguments to be read from the command line.
a_argv --> Which file to open from the command line. 

DESCRIPTION

Checks to make sure the command line arguments are valid.
Opens the file given from the command line.

RETURNS

This is a constructor, no returns.

AUTHOR

Nicole Millian 

DATE

7:30pm 12/15/2015
*/
/**/
FileAccess::FileAccess(int a_argc, char *a_argv[]){
	// Check that there is exactly one run time parameter.
	if (a_argc != 2) {
		cout << "Usage: Assem <FileName>" << endl;
		exit(1);
	}
	// Open the file.  One might question if this is the best place to open the file.
	// One might also question whether we need a file access class.
	m_sfile.open(a_argv[1]);

	// If the open failed, report the error and terminate.
	if (!m_sfile) {
		cout << "Source file could not be opened, assembler terminated." << endl;
		exit(1);
	}
}
/*FileAccess::FileAccess(int a_argc, char *a_argv[])*/

/**/
/*
NAME

FileAccess::~FileAccess() - Deconstructor for FileAccess class. 

SYNOPSIS

FileAccess::~FileAccess();

DESCRIPTION

Closes the file that was opened.

RETURNS

This is a destructor, no returns.

AUTHOR

Nicole Millian

DATE

7:35pm 12/15/2015
*/
/**/
FileAccess::~FileAccess(){
	m_sfile.close();
}
/*FileAccess::~FileAccess()*/

/**/
/*
NAME

FileAccess::GetNextLine - Get the next line from the file.

SYNOPSIS

bool FileAccess::GetNextLine(string &a_buff);
a_buff -> Where the next line read from file will be stored, passed by reference. 

DESCRIPTION

This function will get the next line from the file being read from.
Returns false if the end of file is found, returns true indicating success. 

RETURNS

Returns false if end of file is found.
Returns true if next line was able to be read. 

AUTHOR

Nicole Millian

DATE

7:14pm 12/15/2015
*/
/**/
bool FileAccess::GetNextLine(string &a_buff){
	//Get the next line from the file.
	if (m_sfile.eof()) {
		return false;
	}
	else {
		getline(m_sfile, a_buff);
		// Return indicating success.
		return true;
	}
}
/*bool FileAccess::GetNextLine(string &a_buff)*/

/**/
/*
NAME

FileAccess::Rewind() - Clean the end of file flag and go back to the beginning of the file.

SYNOPSIS

void FileAccess::Rewind()

DESCRIPTION

This function will clear the end of file flag and go back to the beginning.

RETURNS

No returns, the funtion is void.

AUTHOR

Nicole Millian

DATE

7:34pm 12/15/2015
*/
/**/
void FileAccess::Rewind(){
	// Clean the end of file flag and go back to the beginning of the file.
	m_sfile.clear();
	m_sfile.seekg(0, ios::beg);
}
/*void FileAccess::Rewind()*/