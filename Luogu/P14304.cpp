#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		long long n;
		cin >> n;
		long long x = sqrt(n);
		long long ans = (x - 1) * 3;
		if (x * x <= n)
		{
			ans++;
		}
		if (x * (x + 1) <= n)
		{
			ans++;
		}
		if (x * (x + 2) <= n)
		{
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}