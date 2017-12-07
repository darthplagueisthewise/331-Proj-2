/* Record.cpp  */

#include "Record.h"
using namespace std;

Record::Record()
{
	num = 0;
	str = "";
	nptr = nullptr;
}
		
Record::Record(int p_int, string p_str)
{
	num = p_int;
	str = p_str;
	nptr = nullptr;
}

Record::Record(int p_int, string p_str, Node* p_nptr);
{
	num = p_int;
	str = p_str;
	nptr = p_nptr;
}

Record::~Record();
{
	delete nptr;
}

int Node::get_num() const
{
	return num;
}

string Node::get_str() const
{
	return str;
}