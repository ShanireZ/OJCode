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
		int pos = n;
		if (t == 1)
		{
			for (int j = n; j >= i; j--)
			{
				if (a[pos] < a[j])
				{
					pos = j;
				}
			}
		}
		else
		{
			for (int j = n; j >= i; j--)
			{
				if (a[pos] > a[j])
				{
					pos = j;
				}
			}
		}
		swap(a[pos], a[i]);
		cout << a[i] << endl;
	}
	return 0;
}