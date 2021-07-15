#include "QuickSort.h"

void QuickSort::Qsort(vector<int> &vec, int low, int high)
{
	if (high - low < 2)
		return;
	int pivot = partition(vec, low, high);
	Qsort(vec, low, pivot);
	Qsort(vec, pivot+1, high);
}

//inline int QuickSort::partition(vector<int> &vec, int low, int high)
//{
//	int pivot = vec[low];
//	while (low < high)
//	{
//		while (low < high)
//		{
//			if (vec[high] > pivot)
//			{
//				high--;
//			}
//			else
//			{
//				vec[low++] = vec[high];
//				break;
//			}
//		}
//		while (low <high)
//		{
//			if (vec[low] < pivot)
//			{
//				low++;
//			}
//			else
//			{
//				vec[high--] = vec[low];
//				break;
//			}
//		}
//	}
//	cout << "low " << low << " high " << high << endl;
//	print(vec);
//	vec[low] = pivot;
//	return low;
//}
inline int QuickSort::partition(vector<int> &vec, int low, int high)
{
	int pivot = vec[low];
	while (low < high)
	{
		while (low < high && vec[high] >= pivot)
		{
			high--;
		}
		vec[low] = vec[high];
		while (low < high && vec[low] <= pivot)
		{
			low++;
		}
		vec[high] = vec[low];
	}
	vec[low] = pivot;
	return low;
}
