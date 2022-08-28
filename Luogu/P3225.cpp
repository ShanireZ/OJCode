#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int tid, n, gpos, spos, npos, root = 1;
int last[1005], pre[505], to[505], low[1005], dfn[1005], isg[1005], s[1005];
vector<int> dcc[1005];
void tarjan(int now, int from)
{
	dfn[now] = low[now] = ++npos, s[++spos] = now;
	int cnt = 0;
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (t == from)
		{
			continue;
		}
		if (dfn[t] == 0)
		{
			cnt++;
			tarjan(t, now);
			low[now] = min(low[now], low[t]);
			if (dfn[now] <= low[t])
			{
				if ((now == root && cnt >= 2) || (now != root))
				{
					isg[now] = 1;
				}
				dcc[++gpos].push_back(now);
				while (t != s[spos])
				{
					dcc[gpos].push_back(s[spos--]);
				}
				dcc[gpos].push_back(s[spos--]);
			}
		}
		else
		{
			low[now] = min(low[now], dfn[t]);
		}
	}
}
void addEdge(int a, int b, int eid)
{
	pre[eid] = last[a], to[eid] = b;
	last[a] = eid;
}
int main()
{
	cin >> n;
	while (n)
	{
		tid++;
		npos = spos = gpos = 0;
		memset(dfn, 0, sizeof(dfn)), memset(low, 0, sizeof(low));
		memset(pre, 0, sizeof(pre)), memset(to, 0, sizeof(to));
		memset(last, 0, sizeof(last)), memset(s, 0, sizeof(s));
		memset(dcc, 0, sizeof(dcc)), memset(isg, 0, sizeof(isg));
		for (int i = 1; i <= n; i++)
		{
			int a, b;
			cin >> a >> b;
			addEdge(a, b, i * 2), addEdge(b, a, i * 2 - 1);
		}
		tarjan(root, 0);
		long long ans1 = 0, ans2 = 1;
		for (int i = 1; i <= gpos; i++)
		{
			int cnt = 0;
			for (int j = 0; j < dcc[i].size(); j++)
			{
				cnt += isg[dcc[i][j]];
			}
			if (cnt == 0)
			{
				ans1 += 2, ans2 *= dcc[i].size() * (dcc[i].size() - 1) / 2;
			}
			else if (cnt == 1)
			{
				ans1 += 1, ans2 *= dcc[i].size() - 1;
			}
		}
		cout << "Case " << tid << ": " << ans1 << " " << ans2 << endl;
		cin >> n;
	}
	return 0;
}