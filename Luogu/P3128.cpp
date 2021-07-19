#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int read();
struct Node
{
	int v, fa, zson, size, head, dep;
	vector<int> son;
};
Node ns[50005];
int ans;
void init(int now, int dp) // 初始化各属性
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
void divi(int now, int fst) // 重链剖分
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
int lca(int x, int y) // 求LCA
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
void count(int now) // 利用树上差分值求原值
{
	for (int i = 0; i < ns[now].son.size(); i++)
	{
		int id = ns[now].son[i];
		if (id == ns[now].fa)
		{
			continue;
		}
		count(id);
		ns[now].v += ns[id].v;
	}
	ans = max(ans, ns[now].v);
}
int main()
{
	int n = read(), k = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		ns[x].son.push_back(y);
		ns[y].son.push_back(x);
	}
	init(1, 1);
	divi(1, 1);
	for (int i = 1; i <= k; i++)
	{
		int x = read(), y = read();
		int p = lca(x, y);
		int fp = ns[p].fa;
		ns[x].v++, ns[y].v++; // 树上点差分
		ns[p].v--, ns[fp].v--;
	}
	count(1);
	printf("%d\n", ans);
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