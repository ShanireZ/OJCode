#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n, m, k, p;
	cin >> n >> m >> k >> p;
	long long x = min(k / p, m);
	if ((p > k && n != p) || (n == p && p * x != k) ||
		(n != p && (n - p) * (x - 1) < (k - x * p)))
	{
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i <= p)
		{
			cout << x << " " << m - x << endl;
			k -= x;
		}
		else
		{
			long long y = min(x - 1, k);
			cout << y << " " << m - y << endl;
			k -= y;
		}
	}
	return 0;
}