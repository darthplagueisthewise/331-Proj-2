/**
 * @file Record.cpp
 * @author Josh Everly
 * @author Luke Krause
 * @author Sterling Peschl
 * @author Jeremy Nelson-Stalmer
 * @author Tyler Purnick
 *
 * This file contains the methods to store data representing a record
 */

/* Record.cpp  */

#include "Record.h"
using namespace std;

/**
 * @brief Default constructor
 *
 * @return void
 */
Record::Record()
{
	num = 0;
	str = "";
	nptr = nullptr;
}

/**
 * @brief Second constructor to be used if children are not known at this time
 * @param p_int is the integer value belonging to the record
 * @param p_str is the string value belonging to the record
 * @return void
 */
Record::Record(int p_int, string p_str)
{
	num = p_int;
	str = p_str;
	nptr = nullptr;
}

/**
 * @brief Second constructor to be used if children are not known at this time
 * @param p_int is the integer value belonging to the record
 * @param p_str is the string value belonging to the record
 * @param p_nptr is a node pointer pointing to the record's child node
 * @return void
 */
Record::Record(int p_int, string p_str, Node* p_nptr);
{
	num = p_int;
	str = p_str;
	nptr = p_nptr;
}

/**
 * @brief Deconstructor
 *
 * @return void
 */
Record::~Record();
{
	delete nptr;
}

/**
 * @brief Getter function to retrieve the record's integer value
 *
 * @return The record's integer value
 */
int Node::get_num() const
{
	return num;
}

/**
 * @brief Getter function to retrieve the record's string value
 *
 * @return The record's string value
 */
string Node::get_str() const
{
	return str;
}
