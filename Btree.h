/**
 * @file Btree.h
 * @author Josh Everly
 * @author Luke Krause
 * @author Sterling Peschl
 * @author Jeremy Nelson-Stalmer
 *
 * This file contains the specifications for the methods that build and modify a B+ tree
 *
 */

#ifndef _BTREE_H_
#define _BTREE_H_

#include "Node.h"

/**
 * @brief This class contains the methods to build and modify a B+ tree
 */
class BTree
{
	private:

		Node *root;		///< The root node
		int order;		///< The int order value

	public:

		Btree();		
		Btree(Node*, int);
		~Btree();

		void fill_root(const Record&, int i);
		void insert(const Record&);
		void build_tree(std::vector<Record>);
		void split_node(Node**);
};

#endif
