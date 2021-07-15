#include <iostream>
#include <vector>
#include <string>
#include "QuickSort.h"

#define  MAXSIZE 10
using namespace std;
typedef struct 
{
	int r[MAXSIZE + 1];
	int length;
}Sqlist;
void swap(Sqlist *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}
void swap(vector<int> &vec, int i, int j)
{
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}
//—°‘Ò≈≈–Ú
void SelectSort(vector<int> &L)
{
	for (int i = 0; i < L.size(); i++)
	{
		int minpos = i;
		for (int j = i + 1; j < L.size(); j++)
		{
			if (L[j] < L[minpos])
			{
				minpos = j;
			}

		}
		cout << "minpos: " << minpos << endl;
		swap(L, i, minpos);

	}
}

//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(vector<int> &L)
{
	for (int i = 1;i <L.size();i++)
	{
		for (int j = i;j > 0 && L[j] < L[j - 1];j--)
			swap(L, j - 1, j);
	}
}
//œ£∂˚≈≈–Ú
void ShellSort(vector<int> &L)
{
	for (int gap = L.size() / 2; gap > 0; gap /= 2)
	{
		for (int i = 1; i < L.size(); i++)
		{
			for (int j = i; j > 0 && L[j] < L[j - 1]; j -= gap)
				swap(L, j - 1, j);
		}
	}
}
//√∞≈›≈≈–Ú
void bubble(vector<int> &L)
{
	for (int i = 0; i < L.size(); i++)
	{
		for (int j = i; j < L.size(); j++)
		{
			if (L[i] > L[j])
			{
				int temp = L[i];
				L[i] = L[j];
				L[j] = temp;
			}
		}
	}
}
//√∞≈› ∫¿
template <typename T> void bubble1(T* L) {
	for (int i = 0; i < L.size(); i++)
	{
		for (int j = i; j < L.size(); j++)
		{
			if (L[i] > L[j])
			{
				int temp = L[i];
				L[i] = L[j];
				L[j] = temp;
			}
		}
	}
}

void bubble1(vector<int> &L)
{
	for (int i = 0; i < L.size(); i++)
	{
		for (int j = 0; j < L.size()-i-1; j++)
		{
			if (L[j] > L[j+1])
			{
				int temp = L[j+1];
				L[j+1] = L[j];
				L[j] = temp;
			}
		}
	}
}
//øÏÀŸ≈≈–Ú
void quickSort()
{

}
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head = nullptr, *tail = nullptr;
		int carry = 0;
		while (l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + carry;
			if (!head) {
				head = tail = new ListNode(sum % 10);
			}
			else {
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			carry = sum / 10;
			if (l1) {
				l1 = l1->next;
			}
			if (l2) {
				l2 = l2->next;
			}
		}
		if (carry > 0) {
			tail->next = new ListNode(carry);
		}
		return head;
	}
};

int main()
{
	string s = "jjl-001";
	char s1 = s.back() ;
	string s2 = "";
	cout << "s1" << s1 << endl;
	vector<int> Ivec = { 0,11,3,5,12,8,7,10,15,14,4,1,13,2,5,5,5,5 };
	//vector<int> Ivec = { 0,11,3,5,5,6,8,7,6,4,9,4,3,2,45,23,78,12,36,789};
	
	//InsertSort(Ivec);
	//ShellSort(Ivec);
	//bubble1(Ivec);
	//QuickSort q;
	//q.Qsort(Ivec, 0, Ivec.size() - 1);
	//print(Ivec);
	system("pause");
	return 0;
}