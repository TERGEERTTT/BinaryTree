#include <matrix.hpp>
#include <catch.hpp>
#include <iostream>

using namespace std;

SCENARIO("init", "[init]") 
{
	BinaryTree obj;
	REQUIRE(obj.data() == 0);
}
