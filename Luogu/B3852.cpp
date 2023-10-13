#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
struct Edge
{
	int v, w;
	bool operator<(const Edge &oth) const
	{
		if (w == oth.w)
		{
			return v < oth.v;
		}
		return w < oth.w;
	}
};
set<Edge> es[500005];
int w[500005];
int main()
{
	int T = read();
	while (T--)
	{
		int n = read(), m = read();
		for (int i = 1; i <= n; i++)
		{
			es[i].clear(), w[i] = read();
		}
		for (int i = 1; i <= m; i++)
		{
			int u = read(), v = read();
			es[u].insert(Edge{v, w[v]});
		}
		for (int i = 1; i <= n; i++)
		{
			for (Edge e : es[i])
			{
				printf("%d ", e.v);
			}
			printf("\n");
		}
	}
	return 0;
}