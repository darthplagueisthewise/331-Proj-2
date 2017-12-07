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


vector<Record> Node::get_record_vector() const
{
	return record_vector;
}

Record Node::get_record(const int p_loc) const
{
	return record_vector.at(p_loc);
}

void Node::add_record(const Record& p_rec)
{
	record_vector.push_back(p_rec);
	sort(record_vector.begin(), record_vector.end()); // Note: need to implement an overriden > (greater than) operator for Record class
}
int Node::get_vector_size() const
{
	return record_vector.size();
}