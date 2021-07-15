#pragma once
#include <vector>
#include <iostream>

using namespace std;
class QuickSort
{
public:
	void Qsort(vector<int> &vec, int low, int high);
	int partition(vector<int> &vec, int low, int high);
	inline void func() { cout << "  " << endl; }
};
inline void print(vector<int> &L)
{
	for each (auto &var in L)
	{
		cout << var << " ";
	}
	cout << endl;
}
