/* Node.cpp	 */

#include "Node.h"
using namespace std;

Node::Node()
{

}

Node::Node(vector<Record> p_vect)
{
	record_vector = p_vect;
}

vector<Record> Node::get_record_vector()
{
	return record_vector;
}

int Node::get_vector_size()
{
	return record_vector.size();
}