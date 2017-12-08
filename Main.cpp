/**
 * @file Main.cpp
 * @author Josh Everly
 * @author Luke Krause
 * @author Sterling Peschl
 * @author Jeremy Nelson-Stalmer
 * @author Tyler Purnick
 *
 * This file contains the methods to test the functions of the B+ tree
 */

#include "Btree.h"

/*
 * @brief This function tests the functions of the B+ tree
 *
 * @return returns 0 on completion
 */
int main(int argc, char *argv[])
{
	int rec_length=0;
	int numRecs=0;
	std::string IFileName;
	std::ifstream IFile;
	int order;
	cout << "enter input file name" << endl;
	cin >> IFileName;
	cout << "enter order" << endl;
	cin >> order;

	BTree newTree(rootptr,order);

	IFile.open(IFileName.c_str());

	if (IFile.is_open())    // Read in RRNs in here
	{
	  while(IFile >> iRecordPiece)	// Run until all records have been read in
	  {
	     if(iRecordPiece != delimiter)
	     {
	       	iRecord += iRecordPiece;
		rec_length++;
	     }
	     else			// Do everything else once record is built
	     {
		   numRecs++;		// Number of records increases by 1
	           Record newRecord(rec_length, iRecord);	// Make a new object of the Record class
		   if (numRecs < order+1)			// Do this until the root splits
		   {
			 newTree.fill_root(newRecord);		// ^^
		   }
		   else						// Else, do this once root has split
		   {
		   newTree.insert(newRecord);			// Insert items until all records have been read in
	   	   }
	     rec_length = 0;
	     }	// end else
	   }	// end while
	}	// end if
	IFile.close();
	return 0;
}
