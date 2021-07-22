#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read();
struct Node
{
	int fa, zson, size, head, dep;
	vector<int> son;
};
Node ns[500005];
void init(int now, int dp)
{
	ns[now].size++;
	ns[now].dep = dp;
	for (int i = 0; i < ns[now].son.size(); i++)
	{
		int id = ns[now].son[i];
		if (id == ns[now].fa)
		{
			continue;
		}
		ns[id].fa = now;
		init(id, dp + 1);
		ns[now].size += ns[id].size;
		if (ns[id].size > ns[ns[now].zson].size)
		{
			ns[now].zson = id;
		}
	}
}
void divi(int now, int fst)
{
	ns[now].head = fst;
	int id = ns[now].zson;
	if (id == 0)
	{
		return;
	}
	divi(id, fst);
	for (int i = 0; i < ns[now].son.size(); i++)
	{
		id = ns[now].son[i];
		if (id == ns[now].zson || id == ns[now].fa)
		{
			continue;
		}
		divi(id, id);
	}
}
int lca(int x, int y)
{
	int hx = ns[x].head, hy = ns[y].head;
	while (hx != hy)
	{
		if (ns[hx].dep < ns[hy].dep)
		{
			swap(hx, hy);
			swap(x, y);
		}
		x = ns[hx].fa;
		hx = ns[x].head;
	}
	return (ns[x].dep < ns[y].dep) ? x : y;
}
int main()
{
	int n = read(), m = read(), s = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		ns[x].son.push_back(y);
		ns[y].son.push_back(x);
	}
	init(s, 1);
	divi(s, s);
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		printf("%d\n", lca(x, y));
	}
	return 0;
}
int read()
{
	char ch = getchar();
	while (ch != '-' && (ch > '9' || ch < '0'))
	{
		ch = getchar();
	}
	int t = 1, ans = 0;
	if (ch == '-')
	{
		t = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return t * ans;
}