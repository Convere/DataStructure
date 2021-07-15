#include <vector>

using namespace std;
struct BinaryTree
{
	BinaryTree(int a ):value(a){}
	int value;
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;

};
BinaryTree* CreatBiTree()
{
	vector<BinaryTree*> biTv;
	biTv.push_back(new BinaryTree(0));
	biTv.push_back(new BinaryTree(1));
	biTv.push_back(new BinaryTree(2));
	biTv.push_back(new BinaryTree(3));
	biTv.push_back(new BinaryTree(4));
	biTv.push_back(new BinaryTree(5));
	biTv.push_back(new BinaryTree(6));
	biTv.push_back(new BinaryTree(7));
	biTv.push_back(new BinaryTree(8));
	biTv.push_back(new BinaryTree(9));
	biTv.push_back(new BinaryTree(10));
	biTv.push_back(new BinaryTree(11));
	BinaryTree* node8 = biTv.at(8);
	node8->left = biTv[6];
	node8->right = biTv[10];
	biTv[6]->left = biTv[5];
	biTv[6]->right = biTv[7];
	biTv[10]->left = biTv[9];
	biTv[10]->right = biTv[11];
	biTv[11]->left = biTv[2];
	biTv[2]->right = biTv[0];
	return node8;
}