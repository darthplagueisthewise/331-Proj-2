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
		Btree(Node*, int);
		~Btree();

		void fill_root(const Record&, int i);
		void insert(const Record&);
		void build_tree(std::vector<Record>);
		void split_node(Node**);
};

#endif
