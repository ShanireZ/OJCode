#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
	int d, inq;
	vector<int> to;
	vector<int> w;
};
Node ns[2000];
queue<int> q;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		ns[i].d = -0x3f3f3f3f;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ns[u].to.push_back(v);
		ns[u].w.push_back(w);
	}
	ns[1].d = 0;
	q.push(1);
	ns[1].inq = 1;
	while (q.size() > 0)
	{
		int from = q.front();
		ns[from].inq = 0;
		q.pop();
		for (int i = 0; i < ns[from].to.size(); i++)
		{
			int to = ns[from].to[i];
			int dis = ns[from].w[i];
			if (dis + ns[from].d > ns[to].d)
			{
				ns[to].d = ns[from].d + dis;
				if (ns[to].inq == 0)
				{
					q.push(to);
					ns[to].inq = 1;
				}
			}
		}
	}
	if (ns[n].d == -0x3f3f3f3f)
	{
		cout << -1;
	}
	else
	{
		cout << ns[n].d;
	}
	return 0;
}