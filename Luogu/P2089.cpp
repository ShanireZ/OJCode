#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<string> a;

int main()
{
	int n, num3G, num2G, num1G, i, j;
	string situ;
	cin >> n;
	if (n < 10 || n > 30)
	{
		cout << 0;
		return 0;
	}
	for (num3G = 0; num3G <= (n - 10) / 2; num3G++)
	{
		situ = "";
		num2G = n - 10 - num3G * 2;
		num1G = 10 - num2G - num3G;
		if (num1G < 0 || num1G > 10)
		{
			continue;
		}
		for (i = 1; i <= num3G; i++)
		{
			situ.insert(0, "3");
		}
		for (i = 1; i <= num2G; i++)
		{
			situ.insert(0, "2");
		}
		for (i = 1; i <= num1G; i++)
		{
			situ.insert(0, "1");
		}
		a.push_back(situ);
		while (next_permutation(situ.begin(), situ.end()))
		{
			a.push_back(situ);
		}
	}
	sort(a.begin(), a.end());
	cout << a.size() << endl;
	for (i = 0; i < a.size(); i++)
	{
		for (j = 0; j < 10; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}