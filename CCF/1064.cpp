#include <bits/stdc++.h>
using namespace std;

void fibo(int a)
{
	if (a < 3)
	{
		cout << a - 1;
	}
	else
	{
		int fo1 = 0, fo2 = 1;
		for (int i = 3; i <= a; i++)
		{
			int temp = fo1 + fo2;
			fo1 = fo2;
			fo2 = temp;
		}
		cout << fo2;
	}
}

int main()
{
	int n;
	cin >> n;
	fibo(n);
	return 0;
}