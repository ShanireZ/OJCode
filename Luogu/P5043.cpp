#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> to[55];
map<string, int> mp;
string res[55], ans[55];
int n, m, r1[55], r2[55], sz[55];
void dfs1(int now, int from, int id)
{
	sz[now] = 1;
	int ok = 0, cnt = 0;
	for (int nxt : to[now])
	{
		if (nxt == from)
		{
			continue;
		}
		dfs1(nxt, now, id);
		sz[now] += sz[nxt], cnt++;
		ok += (sz[nxt] <= n / 2);
	}
	if (ok == cnt && n - sz[now] <= n / 2)
	{
		r2[id] = r1[id];
		r1[id] = now;
	}
}
void dfs2(int now, int from)
{
	vector<string> chs;
	res[now] = "o";
	for (int nxt : to[now])
	{
		if (nxt == from)
		{
			continue;
		}
		dfs2(nxt, now);
		chs.push_back(res[nxt]);
	}
	sort(chs.begin(), chs.end());
	for (string s : chs)
	{
		res[now] += s;
	}
	res[now] += "x";
}
int main()
{
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			to[j].clear();
		}
		for (int j = 1; j <= n; j++)
		{
			int fa;
			cin >> fa;
			if (fa != 0)
			{
				to[j].push_back(fa), to[fa].push_back(j);
			}
		}
		dfs1(1, 0, i);
		dfs2(r1[i], 0);
		ans[i] = res[r1[i]];
		if (r2[i])
		{
			dfs2(r2[i], 0);
			ans[i] = min(ans[i], res[r2[i]]);
		}
		if (mp[ans[i]] == 0)
		{
			mp[ans[i]] = i;
		}
		cout << mp[ans[i]] << endl;
	}
	return 0;
}