#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int t = i % 2;
		if (t == 1)
		{
			for (int j = n; j > i; j--)
			{
				if (a[j] > a[j - 1])
				{
					swap(a[j], a[j - 1]);
				}
			}
		}
		else
		{
			for (int j = n; j > i; j--)
			{
				if (a[j] < a[j - 1])
				{
					swap(a[j], a[j - 1]);
				}
			}
		}
		cout << a[i] << endl;
	}
	return 0;
}