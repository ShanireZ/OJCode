#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
int f[105];
int main()
{
	int t = read();
	while (t--)
	{
		multiset<int> p[3][105];
		int n = read(), m = read(), r = read(), s = read();
		for (int k = 1; k <= 2; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				f[i] = read();
			}
			for (int i = 1; i <= n; i++)
			{
				p[k][f[i]].insert(read());
			}
		}
		int c[3] = {0, n, n};
		while (c[1] && c[2])
		{
			int hs = 0, ds = 999;
			for (int i = 1; i <= m; i++)
			{
				if ((int)p[s][i].size() && *p[s][i].begin() < ds)
				{
					hs = i, ds = *p[s][i].begin();
				}
			}
			p[s][hs].erase(p[s][hs].begin()), c[s]--;
			if (c[s] == 0)
			{
				break;
			}
			s = 3 - s;
			while ((int)p[s][hs].size() && p[s][hs].upper_bound(ds) != p[s][hs].end())
			{
				auto it = p[s][hs].upper_bound(ds);
				ds = *it;
				p[s][hs].erase(it), c[s]--;
				if (c[s] == 0)
				{
					break;
				}
				s = 3 - s;
			}
			s = 3 - s;
		}
		printf((c[1] == 0) ? "FS wins!\n" : "FR wins!\n");
	}
	return 0;
}