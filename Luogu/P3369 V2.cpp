#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
	int l, r, v, idx, size, ts;
};
Node ns[100005];
int root, pos, a, b, c;
int newnode(int v)
{
	ns[++pos].v = v;
	ns[pos].idx = rand();
	ns[pos].size = 1;
	ns[pos].ts = 1;
	return pos;
}
void updsize(int now)
{
	ns[now].size = ns[ns[now].l].size + ns[ns[now].r].size + ns[now].ts;
}
void split(int now, int v, int &x, int &y)
{
	if (now == 0)
	{
		x = y = 0;
		return;
	}
	if (ns[now].v <= v)
	{
		x = now;
		split(ns[now].r, v, ns[x].r, y);
	}
	else
	{
		y = now;
		split(ns[now].l, v, x, ns[y].l);
	}
	updsize(now);
}
int merge(int x, int y) //x小 y大
{
	if (x == 0 || y == 0)
	{
		return x + y;
	}
	if (ns[x].idx <= ns[y].idx) //合并规则 随便写
	{
		ns[x].r = merge(ns[x].r, y);
		updsize(x);
		return x;
	}
	else
	{
		ns[y].l = merge(x, ns[y].l);
		updsize(y);
		return y;
	}
}
void insert(int x)
{
	split(root, x, a, b);
	split(a, x - 1, a, c);
	if (c)
	{
		ns[c].ts++;
		ns[c].size++;
		root = merge(merge(a, c), b);
	}
	else
	{
		root = merge(merge(a, newnode(x)), b);
	}
}
void del(int x)
{
	split(root, x, a, b);
	split(a, x - 1, a, c);
	ns[c].ts--;
	ns[c].size--;
	if (ns[c].ts)
	{
		root = merge(merge(a, c), b);
	}
	else
	{
		root = merge(a, b);
	}
}
void find_x(int x)
{
	split(root, x - 1, a, b);
	cout << ns[a].size + 1 << endl;
	root = merge(a, b);
}
void find_rkx(int x)
{
	int now = root;
	while (now)
	{
		if (ns[now].size - ns[ns[now].r].size >= x && x >= ns[ns[now].l].size + 1)
		{
			break;
		}
		else if (ns[ns[now].l].size >= x)
		{
			now = ns[now].l;
		}
		else
		{
			x -= ns[now].size - ns[ns[now].r].size;
			now = ns[now].r;
		}
	}
	cout << ns[now].v << endl;
}
void pre(int x)
{
	split(root, x - 1, a, b);
	int now = a;
	while (ns[now].r)
	{
		now = ns[now].r;
	}
	cout << ns[now].v << endl;
	root = merge(a, b);
}
void aft(int x)
{
	split(root, x, a, b);
	int now = b;
	while (ns[now].l)
	{
		now = ns[now].l;
	}
	cout << ns[now].v << endl;
	root = merge(a, b);
}
int main()
{
	srand(709601);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int opt, x;
		cin >> opt >> x;
		if (opt == 1) //插入x
		{
			insert(x);
		}
		else if (opt == 2) //删除x
		{
			del(x);
		}
		else if (opt == 3) //查询x的rank
		{
			find_x(x);
		}
		else if (opt == 4) //查询rank为x的值
		{
			find_rkx(x);
		}
		else if (opt == 5) //找前驱
		{
			pre(x);
		}
		else //找后驱
		{
			aft(x);
		}
	}
	return 0;
}