//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//int s(int* num, int l, int r);
//int f(int* num, int l, int r)
//{
//	if (l == r)
//	{
//		return num[l];
//	}
//	return max(num[l]+s(num, l + 1, r), num[r] + s(num, l, r - 1));
//}
//int s(int* num, int l, int r)
//{
//	if (l == r)
//	{
//		return 0;
//	}
//	return min(f(num, l + 1, r), f(num, l, r - 1));
//};
//
//int winnerMax(int* num, int length)
//{
//	if (num == nullptr || length == 0)
//	{
//		return 0;
//	}
//	return max(f(num, 0, length - 1), s(num, 0, length - 1));
//}
//
//int main()
//{
//	int length = 8;
//	int* num = new int[length]{ 4,6,2,3,7,8,9,3 };
//	cout << winnerMax(num, length) << endl;
//	system("pause");
//}

#include <algorithm>
#include <iostream>

using   namespace std;
int findMIn(int minSum)
{
	int res = 999;
	if (minSum >= 27)
		return -1;
	int a, b;
	for (int i = 0; i <= minSum; i++)
	{
		a = i;
		b = minSum - i;
		if (a > 9 || b > 9)
			continue;
		res = min(a * 10 + b, res);
	}
	return res;
}
int main()
{
	int minNum;
	while (cin >> minNum)
	{
		cout << findMIn(minNum) << endl;
	}
	
	system("pause");
}