#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;

int ChooseNum(int fruitsNum, int mergeNum, int &posF, int &posM)
{
	if(posF == n || fruitsNum > mergeNum)
	{
		posM++;
		return mergeNum;
	}
	else
	{
		posF++;
		return fruitsNum;
	}
}

int main()
{
	int posF = 0, posM = 0, posAdd = 0, total = 0;
	cin >> n;
	int fruits[n];
	int merge[n];
	memset(fruits, 127, sizeof(fruits));
	memset(merge, 127, sizeof(merge));
	for (int i = 0; i < n; i++)
	{
		cin >> fruits[i];
	}
	sort(fruits, fruits + n);
	for (int i = 1; i < n; i++)
	{
		int stack1 = ChooseNum(fruits[posF], merge[posM], posF, posM);
		int stack2 = ChooseNum(fruits[posF], merge[posM], posF, posM);
		int newStack = stack1 + stack2;
		merge[posAdd++] = newStack;
		total += newStack;
	}
	cout << total;
	return 0;
}