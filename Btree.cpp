/**
 * @file Btree.cpp
 * @author Josh Everly
 * @author Luke Krause
 * @author Sterling Peschl
 * @author Jeremy Nelson-Stalmer
 * @author Tyler Purnick
 *
 * This file contains the methods that build and modify a B+ tree
 *
 */

#include "Btree.h"
using namespace std;

/**
 * @brief Default constructor to initialize values
 *
 * @returns void
 */
Btree::Btree()
{
	root = nullptr;
	order = 6;
}

/**
 * @brief Constructor to initialize values
 * @param p_nptr is a node pointer
 * @param p_int is an integer that stores the order value
 * @returns void
 */
Btree::Btree(Node *p_nptr, int p_int)
{
	root = p_nptr;
	order = p_int;
}

/**
 * @brief Deconstructor
 *
 * @returns void
 */
Btree::~Btree()
{
	delete root;
}

/**
 * @brief Fills the root node with keys until it has to split
 * @param p_record is a record to be added to the root
 *
 * @returns void
 */
void Btree::fill_root(const Record& p_record)
{
	root->add_record(p_record);
	if (root->get_vector_size() == order + 1)	// If root is ready to split
	{
		split(root);
	}
}

/**
 * @brief Inserts records into the B+ tree
 * @param p_record is a record to be added
 *
 * @returns void
 */
void Btree::insert(const Record& p_record)
{
	Node *currNode = root;
	bool done = false;
	bool atRoot = false;
	while (!done)	// for each node
	{
		for (int i = 0; i < currNode->get_vector_size(); ++i)	// Scan for each record in node
		{
			if (p_record < currNode->get_record(i))		// If the record is less than
			{
				if (currNode.get_child() != NULL)	// If the record is a parent
				{
					currNode = (currNode.get_record(i))->get_child();
					break;
				}
				else 		// its a leaf
				{
					currNode->add_record(p_record);
					if (currNode->get_vector_size() == order + 1)	// The node is overflowing
					{
						split(currNode);	// Split the node
					}
					done = true;
					break;
				}
			}
			else if ( i == currNode->get_vector_size() - 1)	// Last record in node
			{
				if (currNode.get_child() != NULL)		// If the record is a parent
				{
					currNode = (currNode.get_record(i))->get_child();
					break;
				}
				else 		// its a leaf
				{
					currNode->add_record(p_record);
					if (currNode->get_vector_size() == order + 1)	// The node is overflowing
					{
						split(currNode);	// Split the node
						done = true;
						break;
					}
					
					atRoot = false;
					while (!atRoot)
					{
						Node *parentPtr = searchforparent(root, currNode);
						for (Record rec : parentPtr->get_record_vector())
						{
							if (rec.get_child() == currNode)
							{
								rec.set_string(p_record.get_str());
								break;
							}
						}
						currNode = parentPtr;
						if ( currNode == root)
							atRoot = true;	
					}
					done = true;
					break;
				}
			}
		}
	}
}

*Node Btree::searchforparent(Node* currNode, Node *childptr)
{
	if (currNode == nullptr)
	{
		return currNode;
	}

	for (Record rec : currNode->get_record_vector())
	{
		if (rec.get_child() != childptr)
		{
			return searchforparent(rec.get_child(), childptr);
		}
		else
		{
			return currNode;
		}
	}
}

void Btree::build_tree(vector<Record> p_vect)
{
	if (root != nullptr)
	{
		delete root;
	}

	root = new Node(p_vect);
	
	if (p_vect.size() > order)
	{
		split_node(&root);
	}
}

/**
 * @brief Splits a node and adds the new keys to the parent node
 * @param p_node is the node to be slit
 *
 * @returns void
 */ 								*/  
void Btree::split_node(Node *p_node)
{
	int node_size = p_node->get_vector_size();

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

	int threes = node_size/3; 							// Node must be at least order/2 in size
	int fours = node_size%3;							// We assume order is 6 so the 3 comes from 6/2
	threes -= fours;

	/* Threes and Fours are now set */

	//Node *temp = pnode;
	vector<Record> nodeVec = p_node->get_record_vector();
	//*p_node = new Node();
 	
 	// find parent node
 	if (p_node != root)
 	{
		Node *parent_pointer = searchforparent(root, p_node);

		// find specific record that points to our split node
		Record *record_to_be_erased = parent_pointer->get_record(p_node);

		// erase record
		parent_pointer->erase_record(record_to_be_erased);
	}


 	/* We are assuming the current root is already sorted 		*/
 	/* Create however many nodes of size 4 that we need 		*/ 
	for (int i = 0; i < fours; ++i)
	{
		vector<Record> nvect;
		for (int j = 0; j < 4; ++j)							// Nodes of size 4
		{
			nvect.push_back(nodeVec.at(j));
		}

		Node *temp_ptr = new Node(nvect); 					// dynamically allocate Node so that it lives beyond the function scope => otherwise dangling pointer = badddddd

		var greatest_rec = nvect.end()-1; 					// last element (assuming sorted) in new node is greatest
		int greatest_rec_num = greatest_rec->get_num();
		string greatest_rec_str = greatest_rec->get_str();
		
		Record splitter(greatest_rec_num, greatest_rec_str, temp_ptr);
		parent_pointer->add_record(splitter);

		nodeVec.erase(nodeVec.begin(), nodeVec.begin()+4);
	}

	/* Create however many nodes of size 3 that we need 		*/
	for (int i = 0; i < threes; ++i)
	{
		vector<Record> nvect;
		for (int j = 0; j < 3; ++j)							// Nodes of size 3
		{
			nvect.push_back(nodeVec.at(j));
		}

		Node *temp_ptr = new Node(nvect); 					// dynamically allocate Node so that it lives beyond the function scope => otherwise dangling pointer = badddddd

		var greatest_rec = nvect.end()-1; 					// last element (assuming sorted) in new node is greatest
		int greatest_rec_num = greatest_rec->get_num();
		string greatest_rec_str = greatest_rec->get_str();
		
		Record splitter(greatest_rec_num, greatest_rec_str, temp_ptr);
		parent_pointer->add_record(splitter);

		nodeVec.erase(nodeVec.begin(), nodeVec.begin()+3);
	}

	if (p_node->get_vector_size > order)
	{
		split_node(p_node);
	}

}

