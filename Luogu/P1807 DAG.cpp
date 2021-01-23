#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int lk[2000];  //!是否能从点1出发到达
int ind[2000]; //!入度
int dis[2000]; //!点1到该点距离
struct Line
{
	int to, w;
};
vector<Line> ns[2000]; //!图
queue<int> q;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		Line line;
		line.to = v, line.w = w;
		ind[v]++;
		ns[u].push_back(line);
	}
	dis[n] = -1, lk[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int from = q.front();
		q.pop();
		for (int i = 0; i < ns[from].size(); i++)
		{
			int to = ns[from][i].to;
			int dto = ns[from][i].w;
			ind[to]--;
			if (lk[from] == 1)
			{
				lk[to] = 1;
				if (dis[to] < dis[from] + dto)
				{
					dis[to] = dis[from] + dto;
				}
			}
			if (ind[to] == 0)
			{
				q.push(to);
			}
		}
	}
	cout << dis[n];
	return 0;
}