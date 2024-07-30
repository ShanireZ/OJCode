#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <random>
#include <vector>
using namespace std;
map<long long, int> mp;
vector<int> to[55];
long long res[55][55], r[55], b1, b2, mod = 1e9 + 7;
int sz[55], ans[55], zx1, zx2, n, m, f;
mt19937 rnd(time(0));
void dfs(int now, int from)
{
	int ok = 1;
	for (int nxt : to[now])
	{
		if (from == nxt)
		{
			continue;
		}
		dfs(nxt, now);
		sz[now] += sz[nxt];
		if (sz[nxt] > n / 2)
		{
			ok = 0;
		}
	}
	sz[now] += 1;
	if (ok && n - sz[now] <= n / 2)
	{
		zx1 == 0 ? zx1 = now : zx2 = now;
	}
}
void dfs2(int now, int from, int dp)
{
	int pos = 0;
	for (int nxt : to[now])
	{
		if (from == nxt)
		{
			continue;
		}
		dfs2(nxt, now, dp + 1);
		res[now][++pos] = res[nxt][0];
	}
	sort(res[now] + 1, res[now] + pos + 1);
	res[now][0] = dp * b1 % mod;
	for (int i = 1; i <= pos; i++)
	{
		res[now][0] = res[now][0] * res[now][i] % mod * r[i] % mod * dp % mod;
	}
	res[now][0] = (res[now][0] + b2) % mod;
	// 返回用乘法容易产生哈希碰撞
}
int main()
{
	b1 = rnd() % 233, b2 = rnd() % 277;
	for (int i = 1; i <= 50; i++)
	{
		r[i] = rnd() % mod;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			sz[j] = 0, to[j].clear();
		}
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> f;
			if (f == 0)
			{
				continue;
			}
			to[f].push_back(j), to[j].push_back(f);
		}
		zx1 = zx2 = 0;
		dfs(1, 0);
		dfs2(zx1, 0, 1);
		long long mbs = res[zx1][0];
		if (zx2)
		{
			dfs2(zx2, 0, 1);
			mbs = min(mbs, res[zx2][0]);
		}
		if (mp[mbs] == 0)
		{
			mp[mbs] = i;
		}
		ans[i] = mp[mbs];
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}