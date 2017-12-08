/**
 * @file Node.cpp
 * @author Josh Everly
 * @author Luke Krause
 * @author Sterling Peschl
 * @author Jeremy Nelson-Stalmer
 * @author Tyler Purnick
 *
 * This file contains the methods to access and store data in a node
 *
 */

#include "Node.h"
using namespace std;

/**
 * @brief Default constructor
 * 
 * @return void
 */
Node::Node()
{
}

/**
 * @brief Overloaded constructor
 * @param p_vect is a vector that holds records
 * @return void
 */
Node::Node(vector<Record> p_vect)
{
	record_vector = p_vect;
}

/**
 * @brief Adds a record to the node and sorts the contents of the node
 * @param p_rec is the record to be added into the node
 * @return void
 */
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


/**
 * @brief Returns the node's vector containing records
 * 
 * @return Returns the node's record vector
 */
vector<Record> Node::get_record_vector() const
{
	return record_vector;
}

/**
 * @brief Returns the string value of a specified record
 * @param The location in the node of the record to be returned
 * @return Returns the record at the specified location
 */
Record Node::get_record(const int p_loc) const
{
	return record_vector.at(p_loc);
}

/**
 * @brief 
 * @param 
 * @return 
 */
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

/**
 * @brief Returns the number of records in the node
 * 
 * @return The size of the current node
 */
int Node::get_vector_size() const
{
	return record_vector.size();
}
