//
// Implementation of the symbol table class.
// Has code to add symbols, lookup symbols, and display the symbol table.
//
#include "stdafx.h"
#include "SymTab.h"

/**/
/*
NAME

SymbolTable::AddSymbol - adds a new symbol to the symbol table.

SYNOPSIS

void SymbolTable::AddSymbol(string &a_symbol, int a_loc);
a_symbol --> The symbol to be added to the symbol table
a_loc --> The location to place the symbol.

DESCRIPTION

This function will place the symbol "a_symbol" and its location "a_loc"
in the symbol table. If a symbol is already in the symbol table, then the location
is updated to the location of multiplyDefinedSymbol, which is -999.

RETURNS

The function is void, so there are no returns.

AUTHOR

Nicole Millian

DATE

6:31pm 12/22/2015

*/
/**/
void SymbolTable::AddSymbol(string &a_symbol, int a_loc){
	// If the symbol is already in the symbol table, record it as multiply defined.
	map<string, int>::iterator st;
	st = m_symbolTable.find(a_symbol);
	if (st != m_symbolTable.end()) {
		st->second = multiplyDefinedSymbol;
		return;
	}

	// Record a the  location in the symbol table.
	m_symbolTable[a_symbol] = a_loc;
}
/* void SymbolTable::AddSymbol(string &a_symbol, int a_loc); */

/**/
/*
NAME

SymbolTable::LookupSymbol- Lookup symbol in symbol table, and set a_loc to the location of the symbol.

SYNOPSIS

bool SymbolTable::LookupSymbol(const string &a_symbol, int &a_loc);
a_symbol --> The symbol to look up in the symbol table.
a_loc --> The location the symbol was found at. It's passed by reference so it can
be changed to the location the symbol was found at. 

DESCRIPTION

This function will return true if a symbol was found and false if it was not.
The function will also update the variable that was passed, a_loc, to the location
the symbol was found at if it was found in the table.

RETURNS

The function returns true if the symbol was found in the table, and returns false if it was not. 

AUTHOR

Nicole Millian

DATE

6:35pm 12/22/2015
*/
/**/
bool SymbolTable::LookupSymbol(const string &a_symbol, int &a_loc){

	map<string, int>::iterator st;
	st = m_symbolTable.find(a_symbol);

	if (st != m_symbolTable.end()) {
			a_loc = st->second;
			return true;
	}

	else{
		return false;
	}
}
/*bool SymbolTable::LookupSymbol(const string &a_symbol, int &a_loc);*/

/**/
/*
NAME

SymbolTable::DisplaySymbolTable() - Display the symbol table to the console.

SYNOPSIS

void SymbolTable::DisplaySymbolTable()
No arguments are passed to the function.

DESCRIPTION

This function will loop through the symbol table and display it's contents to the console. 

RETURNS

No returns, the funtion is void. 

AUTHOR

Nicole Millian

DATE

6:55pm 12/22/2015
*/
/**/
void SymbolTable::DisplaySymbolTable() {
	cout << endl;
	cout << "THE SYMBOL TABLE" << endl;
	cout << endl;

	cout << "Symbol #" << setw(10) << "Symbol" << setw(10) << "Location" << endl;
	int i = 0;
	for (map<string, int>::iterator it = m_symbolTable.begin(); it != m_symbolTable.end(); ++it) {
		cout << i << setw(15) << it->first << setw(11) << it->second << '\n';
		i++;
	}
}
/*void SymbolTable::DisplaySymbolTable();*/