#include <iostream>
#include <vector>
using namespace std;
int n, fa[1505], cnt[1505][2];
vector<int> to[1505];
void dfs(int now)
{
	cnt[now][1] = 1;
	for (int i = 0; i < int(to[now].size()); i++)
	{
		int nxt = to[now][i];
		if (nxt == fa[now])
		{
			continue;
		}
		fa[nxt] = now;
		dfs(nxt);
		cnt[now][0] += cnt[nxt][1];
		cnt[now][1] += min(cnt[nxt][0], cnt[nxt][1]);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int now, k, x;
		cin >> now >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> x;
			to[now].push_back(x);
			to[x].push_back(now);
		}
	}
	dfs(0);
	cout << min(cnt[0][0], cnt[0][1]) << endl;
	return 0;
}