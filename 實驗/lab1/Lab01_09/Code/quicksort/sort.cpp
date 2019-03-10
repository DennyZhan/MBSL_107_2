#include <vector>
#include "sort.h"
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(vector<int>& numlist, int front, int end)
{
	/* Let numbers on the left of pivot less than pivot
		, numbers on the right more than pivot.*/
	int pivot = end;
	int i = front - 1;  // the final number of left part

	// Traverse all number, and put numbers less than pivot on ledt part.
	for (int j = front; j <= end - 1; j++)
	{
		if (numlist[j] < numlist[pivot])
		{
			i += 1;
			swap(numlist[i], numlist[j]);
		}
	}
	// Move the pivot to the final of left part.
	i += 1;
	swap(numlist[pivot], numlist[i]);

	return i;
}

void quicksort(vector<int>& numlist, int front, int end)
{
	if (front < end)
	{
		int pivot = partition(numlist, front, end);
		quicksort(numlist, front, pivot - 1);
		quicksort(numlist, pivot + 1, end);
	}
}