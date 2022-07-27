#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005];
int main()
{
	int n, w;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> w;
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--)
	{
		if (a[i] <= w)
		{
			w = a[i];
			break;
		}
	}
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += a[i];
		if (tot > w)
		{
			cout << i - 1 << endl;
			break;
		}
	}
	return 0;
}