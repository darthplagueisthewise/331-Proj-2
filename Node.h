/* Node.h  */
/* Node class */

#ifndef _NODE_H_
#define _NODE_H_

#include "Record.h"
#include <vector>

class Node
{
	private:

		std::vector<Record> record_vector;

	public:

		Node();
		Node(std::vector<Record>);

		void add_record(const Record&);

		std::vector<Record> get_record_vector() const;
		Record get_record(const int) const;
		int get_vector_size() const;

};

#endif