#include <algorithm>
#include <iostream>
using namespace std;
long long a[605][605], b1, b2, c1, c2, mod = 1e9 + 7;
int n, q, k, p, bx, by, cx, cy, h[605], l[605];
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	while (q--)
	{
		fill(h + 1, h + 1 + n, 0), fill(l + 1, l + 1 + n, 0);
		b1 = b2 = c1 = c2 = 1, bx = by = cx = cy = 1;
		cin >> k;
		for (int i = 1; i <= k + k; i++)
		{
			cin >> p;
			i <= k ? h[p] = 1 : l[p] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (h[i] && l[j])
				{
					if (cx == cy)
					{
						c1 = c1 * a[i][j] % mod;
					}
					if (cx + cy == 1 + k)
					{
						c2 = c2 * a[i][j] % mod;
					}
					cy == k ? cy = 1, cx++ : cy++;
				}
				else if (h[i] == 0 && l[j] == 0)
				{
					if (bx == by)
					{
						b1 = b1 * a[i][j] % mod;
					}
					if (bx + by == 1 + n - k)
					{
						b2 = b2 * a[i][j] % mod;
					}
					by == n - k ? by = 1, bx++ : by++;
				}
			}
		}
		cout << ((b1 - b2) * (c1 - c2) % mod + mod) % mod << endl;
	}
	return 0;
}