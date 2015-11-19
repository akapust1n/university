// Ref2Ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

// Объявление узла двоичного дерева. 
struct BTree
{
	char *szText; 
	BTree *Left; 
	BTree *Right;
};

// Объявление указателя на корень дерева. 
BTree *btRoot = 0;

int Add1( BTree **Root, char *szToAdd ); 
int Add2( BTree*& Root, char *szToAdd ); 
void PrintTree( BTree* btRoot );

int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		cerr << "Usage: Refptr [1 | 2]" << "\n"; 
		cerr << "\n\twhere:\n";
		cerr << "\t1 uses double indirection\n";
		cerr << "\t2 uses а reference to а pointer.\n"; 
		cerr << "\n\tInput is from stdin.\n";
		return 1;
	}

char *szBuf = new char[132];

	// Чтение текстового файла из стандартного входного потока и построение двоичного дерева. 
	while( !cin.eof() )
	{
		cin.get( szBuf, 132, '\n' );
		cin.get();
		if( strlen( szBuf ) )
			switch( *argv[1] )
			{
				// Метод 1: Использовать двойную косвенную адресацию. 
				case '1':
					Add1( &btRoot, szBuf );
					break;

				// Метод 2: Использовать ссылку на указатель. 
				case '2':
					Add2( btRoot, szBuf );
					break;

				default:
					cerr << "Illegal value " << *argv[1]
						 << " supplied for add method.\n"
						 << "Choose 1 or 2.\n";
					return -1;
			}
	}

	// Печать отсортированного списка. 
	PrintTree( btRoot );

	return 0;
}

// PrintTree: Прохождение двоичного дерева в обратном порядке. 
void PrintTree( BTree* btRoot )
{
	// Пройти левое поддерево (в обратном порядке). 
	if( btRoot->Left )
		PrintTree( btRoot->Left );

	// Попасть в корень.
	cout << btRoot->szText << "\n";

	// Пройти правое поддерево (в обратном порядке).
	if( btRoot->Right )
		PrintTree( btRoot->Right );
}

// Add1: Добавление узла к двоичному дереву.
//	 Использовать двойную косвенную адресацию.
int Add1( BTree **Root, char *szToAdd )
{
	if( (*Root) == 0 )
	{
		(*Root) = new BTree;
		(*Root)->Left = 0;
		(*Root)->Right = 0;
		(*Root)->szText = new char[strlen( szToAdd ) + 1];
		strcpy( (*Root)->szText, szToAdd );
		return 1;
	}
	else if( strcmp( (*Root)->szText, szToAdd ) > 0 ) 
		return Add1( &((*Root)->Left), szToAdd );
	else
		return Add1( &((*Root)->Right), szToAdd );
}

// Add2: Добавление узла к двоичному дереву.
//	 Использовать ссылку на указатель.
int Add2( BTree*& Root, char *szToAdd )
{
	if( Root == 0 )
	{
		Root = new BTree;
		Root->Left = 0;
		Root->Right = 0;
		Root->szText = new char[strlen( szToAdd ) + 1];
		strcpy( Root->szText, szToAdd ); 
		return 1;
	}
	else if( strcmp( Root->szText, szToAdd ) > 0 )
		return Add2( Root->Left, szToAdd );
	else
		return Add2( Root->Right, szToAdd );
}