#include <algorithm>
#include <iostream>
using namespace std;
int n, f = 1, a[500005];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	while (a[f] == a[f + 1])
	{
		f++;
	}
	int delta = abs(n - f - f);
	for (int i = f + 1; i < n; i++)
	{
		if (a[i] == a[i + 1])
		{
			continue;
		}
		if (delta >= abs(n - i - i))
		{
			delta = abs(n - i - i), f = i;
		}
	}
	cout << a[f + 1] << endl;
	return 0;
}