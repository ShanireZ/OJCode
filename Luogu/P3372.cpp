#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
	int l, r;
	long long tot, lazy; //lazy表示当前节点值还未更新
};
Node ns[400005]; //线段树需4倍大小
long long nums[100005];
long long all, k, type;
void sign(int id, int a, int b) //标记每个区间的范围 计算每个区间的和
{
	ns[id].l = a, ns[id].r = b;
	if (a != b)
	{
		int mid = (a + b) / 2;
		sign(id * 2, a, mid);
		sign(id * 2 + 1, mid + 1, b);
		ns[id].tot = ns[id * 2].tot + ns[id * 2 + 1].tot;
	}
	else
	{
		ns[id].tot = nums[a];
	}
}
void pushdown(int id) //向下传递lazy 并更新节点tot
{
	if (ns[id].lazy)
	{
		long long lazy = ns[id].lazy;
		ns[id].tot += lazy * (ns[id].r - ns[id].l + 1); //更新tot
		if (ns[id].r != ns[id].l)						//如果存在子树
		{
			ns[id * 2].lazy += lazy;
			ns[id * 2 + 1].lazy += lazy;
		}
		ns[id].lazy = 0; //当前节点lazy状态清空
	}
}
void make(int id, int a, int b)
{
	pushdown(id);
	if (ns[id].l == a && ns[id].r == b) //当前区域是目标区域
	{
		if (type == 1)
		{
			ns[id].tot += k * (b - a + 1);
			if (a != b) //处理子树的lazy a!=b说明存在子树
			{
				ns[id * 2].lazy += k;
				ns[id * 2 + 1].lazy += k;
			}
		}
		else
		{
			all += ns[id].tot;
		}
	}
	else //当前区域不是目标区域
	{
		int mid = (ns[id].l + ns[id].r) / 2; //当前区域中点
		int st = 0, ed = 0;					 //存储重合区域的两端
		//左子树l~mid 右子树mid+1~r
		if (a <= mid && b >= ns[id].l) //左子树有重合
		{
			st = max(a, ns[id].l);
			ed = min(b, mid);
			make(id * 2, st, ed);
		}
		if (a <= ns[id].r && b >= mid + 1) //右子树有重合
		{
			st = max(a, mid + 1);
			ed = min(b, ns[id].r);
			make(id * 2 + 1, st, ed);
		}
		if (type == 1) //值有增减才更新tot
		{
			ns[id].tot = ns[id * 2].tot + ns[id * 2 + 1].tot;
			ns[id].tot += (ns[id * 2].r - ns[id * 2].l + 1) * ns[id * 2].lazy;
			ns[id].tot += (ns[id * 2 + 1].r - ns[id * 2 + 1].l + 1) * ns[id * 2 + 1].lazy;
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) //读入
	{
		cin >> nums[i];
	}
	sign(1, 1, n);				 //标记
	for (int i = 1; i <= m; i++) //处理
	{
		int x, y;
		cin >> type >> x >> y;
		if (type == 1) //修改
		{
			cin >> k;
		}
		all = 0;
		make(1, x, y); //处理
		if (type == 2) //查询
		{
			cout << all << endl;
		}
	}
	return 0;
}