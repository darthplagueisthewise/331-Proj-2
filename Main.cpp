/* Main.cpp		*/

#include "Btree.h"

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
	     else						// Do everything else once record is built
	     	{
						 numRecs++;
	           Record newRecord(rec_length, iRecord);
						 if (numRecs < order+1)
						 {
							 newTree.fill_root(newRecord);
						 }
						 else
						 {
						 newTree.insert(newRecord);
					   }
					rec_length = 0;
	     	}	// end else
	   }
	  }
	   IFile.close();
}
