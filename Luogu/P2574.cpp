#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
struct Node
{
	int l, r, cnt0, cnt1, lazy;
};
Node ns[800005];
int tot;
void sign(int id, int l, int r) //标记 初始化
{
	ns[id].l = l, ns[id].r = r;
	if (l == r)
	{
		if (str[l] == '0')
		{
			ns[id].cnt0 = 1;
		}
		else
		{
			ns[id].cnt1 = 1;
		}
	}
	else
	{
		int mid = (l + r) / 2;
		sign(id * 2, l, mid);
		sign(id * 2 + 1, mid + 1, r);
		ns[id].cnt0 = ns[id * 2].cnt0 + ns[id * 2 + 1].cnt0;
		ns[id].cnt1 = ns[id * 2].cnt1 + ns[id * 2 + 1].cnt1;
	}
}
void pushdown(int id) //传递lazytag 并更新cnt
{
	swap(ns[id].cnt0, ns[id].cnt1);
	ns[id].lazy = 0;
	if (ns[id].l != ns[id].r)
	{
		ns[id * 2].lazy = !ns[id * 2].lazy;
		ns[id * 2 + 1].lazy = !ns[id * 2 + 1].lazy;
	}
}
void make(int id, int a, int b, int op)
{
	if (ns[id].lazy) //带有lazytag
	{
		pushdown(id);
	}
	if (ns[id].l == a && ns[id].r == b) //是目标区域
	{
		if (op == 0)
		{
			swap(ns[id].cnt0, ns[id].cnt1);
			if (a != b)
			{
				ns[id * 2].lazy = !ns[id * 2].lazy;
				ns[id * 2 + 1].lazy = !ns[id * 2 + 1].lazy;
			}
		}
		else
		{
			tot += ns[id].cnt1;
		}
	}
	else
	{
		int mid = (ns[id].l + ns[id].r) / 2;
		int st, ed;
		if (a <= mid && b >= ns[id].l)
		{
			st = max(ns[id].l, a);
			ed = min(mid, b);
			make(id * 2, st, ed, op);
		}
		if (a <= ns[id].r && b >= mid + 1)
		{
			st = max(mid + 1, a);
			ed = min(ns[id].r, b);
			make(id * 2 + 1, st, ed, op);
		}
		ns[id].cnt0 = ns[id * 2].cnt0 + ns[id * 2 + 1].cnt0;
		ns[id].cnt1 = ns[id * 2].cnt1 + ns[id * 2 + 1].cnt1;
		if (ns[id * 2].lazy)
		{
			ns[id].cnt0 = ns[id].cnt0 - ns[id * 2].cnt0 + ns[id * 2].cnt1;
			ns[id].cnt1 = ns[id].cnt1 - ns[id * 2].cnt1 + ns[id * 2].cnt0;
		}
		if (ns[id * 2 + 1].lazy)
		{
			ns[id].cnt0 = ns[id].cnt0 - ns[id * 2 + 1].cnt0 + ns[id * 2 + 1].cnt1;
			ns[id].cnt1 = ns[id].cnt1 - ns[id * 2 + 1].cnt1 + ns[id * 2 + 1].cnt0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> str;
	str.insert(0, 1, 'x');
	sign(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int op, l, r;
		cin >> op >> l >> r;
		tot = 0;
		make(1, l, r, op);
		if (op == 1)
		{
			cout << tot << endl;
		}
	}
	return 0;
}