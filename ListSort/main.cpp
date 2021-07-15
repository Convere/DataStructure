#include <iostream>
#include <queue>
#include "BinaryTree.h"


void PreorderTraversal(BinaryTree* root)
{

}

vector<vector<int>> levelTraversal(BinaryTree* root)
{
	vector<vector<int>> ret;
	if (root == nullptr)
	{
		return ret;
	}
	queue<BinaryTree*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		int curLevelSize = Q.size();
		ret.push_back(vector<int>());
		for (int i = 0; i < curLevelSize; i++)
		{
			BinaryTree* node = Q.front();
			ret.back().push_back(node->value);
			
			if (node->left)
			{
				Q.push(node->left);
			}
			if (node->right)
			{
				Q.push(node->right);
			}
			Q.pop();
		}
	}
	return ret;
}

int main()
{
	vector<vector<int>> res;
	res = levelTraversal(CreatBiTree());
	for (int i = 0; i < res.size();i++)
	{
		cout << "[" ;
		for (int j = 0; j < res[i].size();j++)
		{
			if (j== res[i].size()-1)
			{
				cout << res[i][j];
			}
			else
				cout << res[i][j] << ",";
		}
		cout << "]" << endl;
	}
	system("pause");
}
