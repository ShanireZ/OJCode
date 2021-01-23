#include <iostream>
#include <queue>
using namespace std;
int p[25], dp[25], ind[25], road[25], ans[25];
vector<int> way[25];
queue<int> q;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		dp[i] = p[i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int x;
			cin >> x;
			if (x == 1)
			{
				way[i].push_back(j);
				ind[j]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) //拓扑序
	{
		if (ind[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int from = q.front();
		for (int i = 0; i < way[from].size(); i++)
		{
			int to = way[from][i];
			ind[to]--;
			if (dp[from] + p[to] > dp[to])
			{
				dp[to] = dp[from] + p[to];
				road[to] = from;
			}
			if (ind[to] == 0)
			{
				q.push(to);
			}
		}
		q.pop();
	}
	int maxn = 0;
	for (int i = 1; i <= n; i++) //找到最大路径
	{
		if (dp[maxn] < dp[i])
		{
			maxn = i;
		}
	}
	int k = maxn, pos = 1; //回溯路径
	while (k)
	{
		ans[pos++] = k;
		k = road[k];
	}
	for (int i = pos - 1; i >= 1; i--)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	cout << dp[maxn];
	return 0;
}