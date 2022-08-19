#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int n, m, pos, vis[4005], back[4005], forw[4005], base[4005];
vector<int> to[4005];
unordered_map<string, int> mp;
bool dfs(int now, int tag)
{
	if (vis[now] == tag)
	{
		return 0;
	}
	vis[now] = tag;
	for (int i = 0; i < int(to[now].size()); i++)
	{
		int t = to[now][i];
		if (back[t] == 0 || dfs(back[t], tag))
		{
			back[t] = now;
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		mp[a] = ++pos, mp[b] = ++pos;
		base[mp[b]] = mp[a], forw[mp[a]] = mp[b];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		string a, b;
		cin >> a >> b;
		to[mp[a]].push_back(mp[b]);
	}
	for (int i = 1; i <= n; i++)
	{
		memcpy(back + 1, base + 1, n * 2 * sizeof(int));
		back[forw[i * 2 - 1]] = 0;
		if (dfs(i * 2 - 1, i))
		{
			cout << "Unsafe" << endl;
		}
		else
		{
			cout << "Safe" << endl;
		}
	}
	return 0;
}