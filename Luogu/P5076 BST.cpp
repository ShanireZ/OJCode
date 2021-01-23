#include <iostream>
#include <climits>
using namespace std;
struct Node
{
	int v, lc, rc, size;
};
Node ns[10005];
int pos, pre, aft;
void add(int p, int x)
{
	ns[p].size++;
	if (ns[p].v > x) //放在左边
	{
		if (ns[p].lc == 0)
		{
			pos++;
			ns[pos].v = x;
			ns[pos].size = 1;
			ns[p].lc = pos;
		}
		else
		{
			add(ns[p].lc, x);
		}
	}
	else if(ns[p].v < x) //放在右边
	{
		if (ns[p].rc == 0)
		{
			pos++;
			ns[pos].v = x;
			ns[pos].size = 1;
			ns[p].rc = pos;
		}
		else
		{
			add(ns[p].rc, x);
		}
	}
}
void fp(int p, int x)
{
	if (ns[p].v >= x)
	{
		if (ns[p].lc != 0)
		{
			fp(ns[p].lc, x);
		}
	}
	else
	{
		pre = max(pre, ns[p].v);
		if (ns[p].rc != 0)
		{
			fp(ns[p].rc, x);
		}
	}
}
void fa(int p, int x)
{
	if (ns[p].v <= x)
	{
		if (ns[p].rc != 0)
		{
			fa(ns[p].rc, x);
		}
	}
	else
	{
		aft = min(aft, ns[p].v);
		if (ns[p].lc != 0)
		{
			fa(ns[p].lc, x);
		}
	}
}
int findv(int p, int x)
{
	if (p == 0)
	{
		return 0;
	}
	if (ns[p].v == x)
	{
		return ns[ns[p].lc].size;
	}
	else if (ns[p].v > x)
	{
		return findv(ns[p].lc, x);
	}
	else
	{
		return findv(ns[p].rc, x) + ns[p].size - ns[ns[p].rc].size;
	}
}
int findr(int p, int x)
{
	if (ns[p].size - ns[ns[p].rc].size >= x && ns[ns[p].lc].size + 1 <= x)
	{
		return ns[p].v;
	}
	else if (ns[ns[p].lc].size >= x)
	{
		return findr(ns[p].lc, x);
	}
	else
	{
		return findr(ns[p].rc, x - (ns[p].size - ns[ns[p].rc].size));
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, x;
		cin >> t >> x;
		if (t == 1) //查找x的rank
		{
			cout << findv(1, x) + 1 << endl;
		}
		else if (t == 2) //查找rank x
		{
			cout << findr(1, x) << endl;
		}
		else if (t == 3) //前驱
		{
			pre = -2147483647;
			fp(1, x);
			cout << pre << endl;
		}
		else if (t == 4) //后驱
		{
			aft = 2147483647;
			fa(1, x);
			cout << aft << endl;
		}
		else //插入
		{
			if (pos == 0)
			{
				pos++;
				ns[pos].v = x;
				ns[pos].size = 1;
			}
			else
			{
				add(1, x);
			}
		}
	}
	return 0;
}