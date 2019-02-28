#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

const int INPUT_NUMBER = 10;

void printNumlist(const vector<int>& numlist)
{
	cout << "list: ";

	for (auto num : numlist)
		cout << num << ' ';

	cout << endl;
}

vector<int> inputNumlist()
{
	int num = 0;
	vector<int> numlist;

	cout << "Please enter " << INPUT_NUMBER << " numbers." << endl;
	cout << ">>> ";

	for (int i = 0; i < INPUT_NUMBER; i++)
	{
		cin >> num;
		numlist.push_back(num);
	}
	return numlist;
}

int main()
{
	vector<int> numlist;

	numlist = inputNumlist();
	cout << "input:" << endl;;
	printNumlist(numlist);
	quicksort(numlist, 0, INPUT_NUMBER - 1);
	cout << "after sorted" << endl;
	printNumlist(numlist);
	return 0;
}