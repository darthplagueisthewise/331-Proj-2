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

		void add_record_to_node(Record);
};

#endif