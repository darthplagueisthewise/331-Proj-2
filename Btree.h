/* Btree.h  */
/* BTree class */

#ifndef _BTREE_H_
#define _BTREE_H_

#include "Node.h"

class BTree
{
	private:

		Node *root;
		int order;

	public:

		Btree();
		Btree(Node*);
		~Btree();

		void add_record(const Record&);
		void build_tree(std::vector<Record>)
};

#endif