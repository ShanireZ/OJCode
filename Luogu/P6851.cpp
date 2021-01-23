#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
	int id, v;
};
bool cmp(Node x, Node y)
{
	return x.v > y.v;
}
vector<Node> xc[100005], xd[100005];
int ans[100005];
long long read();
int main()
{
	int n = read(), m = read();
	long long c = read(), tot = read();
	for (int i = 1; i <= n; i++)
	{
		int tp = read();
		Node tmp;
		tmp.id = i;
		tmp.v = read();
		xd[tp].push_back(tmp);
	}
	for (int i = 1; i <= m; i++)
	{
		int tp = read();
		Node tmp;
		tmp.id = i;
		tmp.v = read();
		xc[tp].push_back(tmp);
	}
	for (int i = 1; i <= 100000; i++) //探索每种花色
	{
		sort(xd[i].begin(), xd[i].end(), cmp);
		sort(xc[i].begin(), xc[i].end(), cmp);
		if (xc[i].size() > xd[i].size()) //xc牌多 xd没牌只能弃一些轮次
		{
			tot -= (xc[i].size() - xd[i].size()) * c;
		}
		int st = 0, j = 0;
		while (st < xc[i].size() && j < xd[i].size()) //探索到 xd无法赢 或 xc xd其中一个没牌了为止
		{
			if (xd[i][j].v >= xc[i][st].v) //xd赢 xd的j匹配xc的k
			{
				tot += xd[i][j].v + c;
				ans[xc[i][st].id] = xd[i][j].id;
				xc[i].erase(xc[i].begin() + st);
				j++;
				continue;
			}
			st++;
		}
		while (j < xd[i].size() && xc[i].size()) //xd必输局 随便匹配了
		{
			tot += xd[i][j].v - c;
			ans[xc[i][0].id] = xd[i][j].id;
			xc[i].erase(xc[i].begin());
			j++;
		}
	}
	printf("%lld\n", tot);
	for (int i = 1; i <= m; i++)
	{
		if (ans[i] != 0)
		{
			printf("%d\n", ans[i]);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
long long read() //快读
{
	char ch = getchar();
	while ((ch > '9' || ch < '0') && ch != '-')
	{
		ch = getchar();
	}
	long long t = 1, n = 0;
	if (ch == '-')
	{
		t = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		n = n * 10 + ch - '0';
		ch = getchar();
	}
	return n * t;
}