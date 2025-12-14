#include <algorithm>
#include <iostream>
using namespace std;
int k[10000005], prim[3205], vis[3205], pos, n, a, ans = 1;
int main()
{
	for (int i = 2; i <= 3200; i++)
	{
		if (vis[i] == 0)
		{
			prim[++pos] = i;
			for (int j = 2; i * j <= 3200; j++)
			{
				vis[i * j] = 1;
			}
		}
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		int ex = 1;
		for (int j = 1; j <= pos && a != 1; j++)
		{
			int t = 0;
			while (a % prim[j] == 0)
			{
				a /= prim[j], t++;
			}
			if (t % 2 == 1)
			{
				ex *= prim[j];
			}
		}
		k[ex * a]++;
	}
	for (int i = 1; i <= 10000000; i++)
	{
		if (k[i] > k[ans])
		{
			ans = i;
		}
	}
	cout << k[ans] << endl;
	return 0;
}