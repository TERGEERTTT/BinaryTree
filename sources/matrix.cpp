#include "matrix.hpp"

template<typename T>
BinaryTree<T>::BinaryTree() :data(0), left{ nullptr }, right{ nullptr }
{
}

template<typename T>
int BinaryTree::data() const
{
	return data;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	delete *root;
}

template<typename T>
void BinaryTree<T>::add_node(const T& data, Node<T> *&MyTree)
{
	if (MyTree == NULL)
	{
		MyTree = new Node;
		MyTree->data = data;
		MyTree->left = MyTree->right = NULL;
	}
	if (data < MyTree->data)
	{
		if (MyTree->left != NULL)
			add_node(data, MyTree->left);
		else
		{
			MyTree->left = new Node;
			MyTree->left->left = MyTree->left->right = NULL;
			MyTree->left->data = data;
		}

	}
	if (data > MyTree->data)
	{
		if (MyTree->right != NULL)
			add_node(data, MyTree->right);
		else
		{
			MyTree->right = new Node;
			MyTree->right->left = MyTree->right->right = NULL;
			MyTree->right->data = data;
		}
	}
}

template<typename T>
Node<T> *search(const T& buff, Node<T> *&MyTree)
{
	*MyTree = root;
	if (MyTree == NULL)
	{
		return NULL;
	}
	if (MyTree->data == buff)
	{
		return MyTree;
	}
	if (MyTree->data > buff)
	{
		return search(buff, MyTree->left);
	}
	else
	{
		return search(buff, MyTree->right);
	}
}

template<typename T>
void BinaryTree<T>::write_in(const std::string filename) const
{
	T buff;
	std::ifstream file_1(filename);
	while (file_1.eof())
	{
		add_node(buff);
		file_1 >> buff;
	}
	file_1.close();
}

template<typename T>
void BinaryTree<T>::ost(std::ostream& rez, Node<T> *data)
{
	if (data == NULL)
	{
		return 0;
	}
	else
	{
		ost(rez, data->left);
		ost(rez, data->right);
	}
}