#include <algorithm>
#include <iostream>
using namespace std;
int T, n, a[1005];
int main()
{
	cin >> T;
	a[0] = 1e9 + 7;
	while (T--)
	{
		cin >> n;
		int pj = 0, pm = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i % 2 == 1 && a[i] < a[pj])
			{
				pj = i;
			}
			else if (i % 2 == 0 && a[i] < a[pm])
			{
				pm = i;
			}
		}
		if (n % 2 == 1)
		{
			cout << "Jerry" << endl;
		}
		else
		{
			if (a[pj] > a[pm])
			{
				cout << "Jerry" << endl;
			}
			else if (a[pj] < a[pm])
			{
				cout << "Tom" << endl;
			}
			else
			{
				cout << (pj < pm ? "Tom" : "Jerry") << endl;
			}
		}
	}
	return 0;
}