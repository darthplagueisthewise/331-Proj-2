/**
 * @file Record.h
 * @author Josh Everly
 * @author Luke Krause
 * @author Sterling Peschl
 * @author Jeremy Nelson-Stalmer
 * @author Tyler Purnick
 *
 * This file contains the specifications for the methods to store data representing a record
 */

/* Record.h  */
/* record class */

#ifndef _RECORD_H_
#define _RECORD_H_

#include <string>

/*
 * @brief This class stores data representing a record
 */
class Record
{
	private:

		int num;		///< The record's integer value
		std::string str;	///< The record's string value
		Node *nptr;		///< Node pointer pointing to the record's child node (NULL if childless)

	public:

		Record();
		Record(int, std::string);
		Record(int, std::string, Node*);
		~Record();

		/* Getter Functions */
		int get_num() const;
		/**
		 * @brief This function returns the node pointer to the record's child
		 * @return The node pointer to the record's child
		 */
		Node* get_child(){ return nptr; } 
	
		std::string get_str() const;
	
		/**
		 * @brief This function sets the string value of the record to a new value and updates the integer value
		 * @param newStr is the new string value to put into the record
		 */
		void set_string(std::string newStr) { str = newStr; num = newStr.strlen();}

};

#endif
