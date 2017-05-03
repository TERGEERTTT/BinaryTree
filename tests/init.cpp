#include <BinaryTree.hpp>
#include <catch.hpp>

SCENARIO("bst init", "[init]") 
{
	BinarySearchTree<int> bst;
	REQUIRE(bst.count() == 0);
}

SCENARIO("bst init", "[init]") 
{
	BinarySearchTree<int> bst;
  bst.insertElement(8);
	bst.insertElement(3);
	REQUIRE(std::cout<<bst);
}
