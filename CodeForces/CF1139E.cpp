#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n, m, d, pos;
int p[5005], c[5005], del[5005], vis[5005], back[5005], ans[5005], status[5005];
vector<int> to[5005];
bool dfs(int now, int tag)
{
	if (vis[now] == tag)
	{
		return false;
	}
	vis[now] = tag;
	for (int i = 0; i < int(to[now].size()); i++)
	{
		int t = to[now][i];
		if (back[t] == -1 || dfs(back[t], tag))
		{
			back[t] = now;
			return true;
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	cin >> d;
	for (int i = 1; i <= d; i++)
	{
		cin >> del[i];
		status[del[i]] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (status[i] == 0)
		{
			to[p[i]].push_back(c[i]);
		}
	}
	memset(back, -1, sizeof(back));
	for (int i = d; i >= 1; i--)
	{
		// 跑一遍二分图最大匹配 并 输出
		for (int j = ans[i + 1]; j <= 5001; j++)
		{
			if (dfs(j, ++pos) == false)
			{
				ans[i] = j;
				break;
			}
		}
		// 加边
		int id = del[i];
		to[p[id]].push_back(c[id]);
	}
	for (int i = 1; i <= d; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}