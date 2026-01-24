#include <algorithm>
#include <iostream>
using namespace std;
int n, a[500005];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int delta = n, res = a[n];
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == a[i + 1])
		{
			continue;
		}
		if (delta >= abs(n - i - i))
		{
			delta = abs(n - i - i);
			res = a[i + 1];
		}
	}
	cout << res << endl;
	return 0;
}