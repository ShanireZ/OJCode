#include <algorithm>
#include <iostream>
using namespace std;
long long a[500005], b[500005], qz[500005];
int main()
{
	int c, n, k, x;
	cin >> c >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		a[i] = b[i] = x;
	}
	sort(b + 1, b + n + 1, greater<int>());
	for (int i = 1; i <= n; i++)
	{
		qz[i] = qz[i - 1] + b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		long long ans = 0;
		if (a[i] > b[k]) // 第i个数的后排名太小了,把它后面一直到第k名加大至它的值
		{
			// for (int j = k; b[j] < a[i]; j--)
			// {
			// 	ans += a[i] - b[j];
			// }
			int p = upper_bound(b + 1, b + 1 + n, a[i], greater<int>()) - b;
			ans += a[i] * (k - p + 1) - (qz[k] - qz[p - 1]);
		}
		if (a[i] < b[k]) // 第i个数的前排名太小了,把它加大至第k名的值
		{
			ans = b[k] - a[i];
		}
		cout << ans << endl;
	}
	return 0;
}