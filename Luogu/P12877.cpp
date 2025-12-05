#include <algorithm>
#include <iostream>
using namespace std;
long long ex, n, a[1000005], b[500005], bod[500005];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ex += a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		ex -= b[i];
	}
	if (ex % n != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	ex /= n;
	for (int i = 1; i <= n; i++)
	{
		a[i] -= ex;
		a[i + n] = a[i];
	}
	for (int i = 2, j = 1; i <= n; i++)
	{
		if (j != 1 && b[i] != b[j])
		{
			j = bod[j - 1];
		}
		bod[i] = (b[i] == b[j] ? ++j : 0);
	}
	for (int i = 1, j = 1; i <= n * 2; i++)
	{
		if (j != 1 && a[i] != b[j])
		{
			j = bod[j - 1];
		}
		j += (a[i] == b[j]);
		if (j > n)
		{
			cout << i - n << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}