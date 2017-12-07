/* record.h  */
/* record class */

#ifndef _RECORD_H_
#define _RECORD_H_

#include <string>

class Record
{
	private:

		int num;
		std::string str;
		Node *nptr;

	public:

		Record();
		Record(int, std::string);
		Record(int, std::string, Node*);

};

#endif