/* Btree.cpp  */

#include "Btree.h"
using namespace std;

Btree::Btree()
{
	root = nullptr;
	order = 6;
}

Btree::Btree(Node *p_nptr)
{
	root = p_nptr;
	order = 6;
}

Btree::~Btree()
{
	delete root;
}

void Btree::add_record(const Record& p_record)
{

}

void Btree::build_tree(vector<Record> p_vect)
{
	if (root != nullptr)
	{
		delete root;
	}

	root = new Node(p_vect);
	int curr_node_size = root->get_vector_size();

	if (curr_node_size > order)
	{
		split_node(curr_node_size);
	}
}

/* split_node public function */
/* DISCLAIMER: THIS FUNCTION CURRENTLY IS ONLY BEING PROGRAMMED TO SPLIT THE ROOT NODE (it is a wip thank you)  */  
void Btree::split_node(int p_size)
{
	/* 	
		The code below does the following:
		Assume the size of the node we need to split is 17 (17 > order)
		Assuming order is equal to 6, we divide by 3
		Then "threes" will be set to 5 and "fours" will be set to 2
		After subtracting "fours" from "threes", "threes" will be set to 3
		So: threes = 3 and fours = 2
		This means that the Node needs to be split into 3 sub-nodes of size 3 and 2 sub-nodes of size 4
		4 + 4 + 3 + 3 + 3 = 17
	*/

	int threes = p_size/(order/2); 							// Node must be at least order/2 in size, we assume order is an even number
	int fours = p_size%(order/2);
	threes -= fours;

	/* Threes and Fours are now set */

	Node *temp = root;
	root = new Node();
 
 	/* We are assuming the current root is already sorted */
	for (int i = 0; i < fours; ++i)
	{
		vector<Record> nvect;
		for (int j = (i * 4); j < ((i+1)*4); ++j)
		{
			nvect.push_back(temp->get_record(i));
		}

		Node *temp_ptr = new Node(nvect); 					// dynamically allocate Node so that it lives being function scope => otherwise dangling pointer = badddddd

		var greatest_rec = nvect.end()-1; 					// last element (assuming sorted) in new node is greatest
		int greatest_rec_num = greatest_rec->get_num();
		string greatest_rec_str = greatest_rec->get_str();
		
		Record splitter(greatest_rec_num, greatest_rec_str, temp_ptr);
		root->add_record()
	}
}