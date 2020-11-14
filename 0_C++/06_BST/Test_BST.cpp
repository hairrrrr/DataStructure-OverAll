#include"BST.hpp"

int main(void)
{
	BST<int> bst;

	bst.show();

	//bst.insert(9);
	//bst.insert(5);
	////bst.insert(2);
	//bst.insert(11);
	//bst.insert(8);
	//bst.insert(7);
	////bst.insert(3);
	////bst.insert(1);

	bst.insert(9);
	bst.insert(7);
	bst.insert(11);
	bst.insert(3);
	bst.insert(2);
	bst.insert(5);
	bst.insert(4);

	bst.show();

	bst.erase(7);

	bst.show();

	return 0;
}