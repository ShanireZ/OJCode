#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int ind[100005], dp[100005];
vector<int> to[100005];
queue<int> q;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		to[x].push_back(y), ind[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < int(to[now].size()); i++)
		{
			int nxt = to[now][i];
			ind[nxt]--, dp[nxt] = max(dp[nxt], dp[now] + 1);
			if (ind[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << "\n";
	}
	return 0;
}