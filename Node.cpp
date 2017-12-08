/* Node.cpp	 */

#include "Node.h"
using namespace std;

/* Default Constructor */
Node::Node()
{
}

/* Overloaded Constructor */
Node::Node(vector<Record> p_vect)
{
	record_vector = p_vect;
}


void Node::add_record(const Record& p_rec)
{
	record_vector.push_back(p_rec);
	sort(record_vector.begin(), record_vector.end()); // Note: need to implement an overriden > (greater than) operator for Record class
}

void Node::erase_record(Record *p_rptr)
{
	record_vector.erase(p_rptr);
	sort(record_vector.begin(), record_vector.end());
}

vector<Record> Node::get_record_vector() const
{
	return record_vector;
}

Record Node::get_record(const int p_loc) const
{
	return record_vector.at(p_loc);
}

Node* Node::get_record(Node* p_nptr) const
{
	for (Record r : record_vector)
	{
		if (r.get_child() == p_nptr)
		{
			return &r;
		}
	}
	return nullptr;
}

int Node::get_vector_size() const
{
	return record_vector.size();
}