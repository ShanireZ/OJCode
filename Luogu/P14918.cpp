#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int prim[325], vis[325], a[100005], t[100005], ans, n, pos;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 2; i <= 316; i++)
	{
		if (vis[i] == 0)
		{
			prim[++pos] = i;
		}
		for (int j = 1; j <= pos && i * prim[j] <= 316; j++)
		{
			vis[i * prim[j]] = 1;
			if (i % prim[j] == 0)
			{
				break;
			}
		}
	}
	for (int i = 1; i <= pos; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			t[j] = 0;
			while (a[j] % prim[i] == 0)
			{
				a[j] /= prim[i], t[j]++;
			}
		}
		sort(t + 1, t + n + 1);
		int res1 = 0, res2 = 0;
		for (int j = 1; j <= n; j++)
		{
			res1 += abs(t[j] - t[n / 2]);
			res2 += abs(t[j] - t[n / 2 + 1]);
		}
		ans += min(res1, res2);
	}
	for (int i = 1; i <= n; i++)
	{
		ans += (a[i] != 1);
	}
	cout << ans << endl;
	return 0;
}