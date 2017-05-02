//
//		File access to source file.
//		Has public functions to GetNextLine and Rewind the file.
//
#ifndef _FILEACCESS_H  // This is the way that multiple inclusions are defended against often used in UNIX
#define _FILEACCESS_H // We use pramas in Visual Studio.  See other include files

#include <fstream>
#include <string>

class FileAccess {

public:

	// Opens the file.
	FileAccess(int argc, char *argv[]);

	// Closes the file.
	~FileAccess();

	// Get the next line from the source file.
	bool GetNextLine(string &a_buff);

	// Put the file pointer back to the beginning of the file.
	void Rewind();

private:

	ifstream m_sfile;		// Source file object.
};
#endif
