#include <iostream> 
#include <string> 
#include <fstream> 
#include <cstdint>

using namespace std;

template<typename T>
struct Node
{
	T	data;
	Node *left;
	Node *right;
};


template<typename T>
class BinaryTree
{
private:
	Node<T> *root;
public:
	BinaryTree();
	~BinaryTree();
	int data()const;
	void add_node(const T&, Node<T>*&);
	Node<T> *search(const T&);
	void write_in(const string)const;
	void ost(std::ostream&, Node<T>*);
};
