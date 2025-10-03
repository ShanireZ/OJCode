#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define MX 2000005
vector<int> to[MX];
stack<int> s;
int dfn[MX], low[MX], g[MX], n, m, npos, gpos;
void tarjan(int now)
{
	dfn[now] = low[now] = ++npos, s.push(now);
	for (int nxt : to[now])
	{
		if (dfn[nxt] == 0)
		{
			tarjan(nxt);
			low[now] = min(low[now], low[nxt]);
		}
		else if (g[nxt] == 0)
		{
			low[now] = min(low[now], dfn[nxt]);
		}
	}
	if (dfn[now] == low[now])
	{
		++gpos;
		while (s.top() != now)
		{
			g[s.top()] = gpos, s.pop();
		}
		g[now] = gpos, s.pop();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, a, y, b;
		cin >> x >> a >> y >> b;
		to[x + n * a].push_back(y + n * !b);
		to[y + n * b].push_back(x + n * !a);
	}
	for (int i = 1; i <= n + n; i++)
	{
		if (dfn[i] == 0)
		{
			tarjan(i);
		}
		if (i > n && g[i] == g[i - n])
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	cout << "POSSIBLE" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << (g[i] < g[n + i] ? 1 : 0) << " "; // 输出更下游的结果,其后续推论更少,不易产生冲突
	}
	cout << endl;
	return 0;
}