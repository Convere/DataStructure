#include <iostream>
#include "BinaryTree.h"
using namespace std;

void morris(BinaryTree* head)
{
	if (head == nullptr)
		return;
	BinaryTree* cur = head;
	BinaryTree* mostRight = nullptr;
	while (cur != nullptr)
	{
		mostRight = cur->left;
		if (mostRight != nullptr)
		{
			while (mostRight != nullptr && mostRight != cur)
			{
				mostRight = mostRight->right;
			}
			if (mostRight == nullptr)
			{	
				mostRight->right = cur;
				//ǰ��
				cur = cur->left;
				continue;
			}
			else
			{

				mostRight->right = nullptr;
			}
		}
		else
		{
			//ǰ��
		}
		//����
		cur = cur->right;
	}
}
int main()
{

}