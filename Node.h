/**
 * @file Node.h
 * @author Josh Everly
 * @author Luke Krause
 * @author Sterling Peschl
 * @author Jeremy Nelson-Stalmer
 * @author Tyler Purnick
 *
 * This file contains the specifications for the methods to access and store data in a node
 *
 */

/* Node.h  */
/* Node class */

#ifndef _NODE_H_
#define _NODE_H_

#include "Record.h"
#include <vector>

/**
 * @brief This class contains a vector to store records as well as methods to access and modify that vector
 */
class Node
{
	private:

		std::vector<Record> record_vector;

	public:

		Node();
		Node(std::vector<Record>);

		void add_record(const Record&);
		void erase_record(Record*);

		std::vector<Record> get_record_vector() const;
		Record get_record(const int) const;
		Node* get_record(Node*) const;
		int get_vector_size() const;

};

#endif
