#include <cstdio>
using namespace std;
int read() //快讀
{
	char ch = getchar();
	while ((ch > '9' || ch < '0') && ch != '-')
	{
		ch = getchar();
	}
	int t = 1, n = 0;
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
struct Node
{
	int l, r, v;
};
Node ns[16000005]; //節點池
int n, m, pos;
int rootfa[200005], rootdp[200005]; //每個版本的並查集根節點 和 深度根節點
void make(int l, int r, int &p)		//建置初始並查集的線段樹
{
	p = ++pos;
	if (l == r)
	{
		ns[p].v = l;
		return;
	}
	int m = (l + r) >> 1;
	make(l, m, ns[p].l);
	make(m + 1, r, ns[p].r);
}
void edit(int l, int r, int old, int &now, int p, int x) //將old所在版本的p節點值修改為x，生成now所在版本
{
	now = ++pos;
	if (l == r)
	{
		ns[now].v = x;
		return;
	}
	ns[now] = ns[old];
	int m = (l + r) >> 1;
	if (p <= m)
	{
		edit(l, m, ns[old].l, ns[now].l, p, x);
	}
	else
	{
		edit(m + 1, r, ns[old].r, ns[now].r, p, x);
	}
}
int findx(int l, int r, int p, int x) //查找p所在版本中第x個節點的值
{
	if (l == r)
	{
		return ns[p].v;
	}
	int m = (l + r) >> 1;
	if (x <= m)
	{
		return findx(l, m, ns[p].l, x);
	}
	else
	{
		return findx(m + 1, r, ns[p].r, x);
	}
}
int dfn(int ver, int x) //並查集函式 查詢ver版本的x的父節點 不進行路徑壓縮
{
	int xfa = findx(1, n, rootfa[ver], x); //x節點的父節點
	if (xfa != x)
	{
		xfa = dfn(ver, xfa);
	}
	return xfa;
}
void merge(int ver, int a, int b) //合併a和b所在集合 按秩合併
{
	int ga = dfn(ver - 1, a);
	int gb = dfn(ver - 1, b);
	if (ga != gb)
	{
		int dpa = findx(1, n, rootdp[ver - 1], ga);
		int dpb = findx(1, n, rootdp[ver - 1], gb);
		if (dpa < dpb)
		{
			edit(1, n, rootfa[ver - 1], rootfa[ver], ga, gb);
			rootdp[ver] = rootdp[ver - 1];
		}
		else if (dpa > dpb)
		{
			edit(1, n, rootfa[ver - 1], rootfa[ver], gb, ga);
			rootdp[ver] = rootdp[ver - 1];
		}
		else
		{
			edit(1, n, rootfa[ver - 1], rootfa[ver], ga, gb);
			edit(1, n, rootdp[ver - 1], rootdp[ver], gb, dpb + 1);
		}
	}
	else
	{
		rootfa[ver] = rootfa[ver - 1];
		rootdp[ver] = rootdp[ver - 1];
	}
}
int main()
{
	n = read(), m = read();
	make(1, n, rootfa[0]);
	for (int i = 1; i <= m; i++)
	{
		int opt = read(), a = read(), b;
		if (opt == 1)
		{
			b = read();
			merge(i, a, b);
		}
		else if (opt == 2)
		{
			rootfa[i] = rootfa[a];
			rootdp[i] = rootdp[a];
		}
		else
		{
			b = read();
			rootfa[i] = rootfa[i - 1];
			rootdp[i] = rootdp[i - 1];
			int ga = dfn(i, a);
			int gb = dfn(i, b);
			if (ga == gb)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}