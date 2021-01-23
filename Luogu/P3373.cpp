#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
	int l, r;
	long long tot, lazyp, lazym; //lazytag表示当前节点值还未更新
};
Node ns[400005]; //线段树需4倍大小
long long nums[100005];
long long all, k, type, p;
void sign(int id, int a, int b) //标记每个区间的范围 计算每个区间的和
{
	ns[id].l = a, ns[id].r = b, ns[id].lazym = 1;
	if (a != b)
	{
		int mid = (a + b) / 2;
		sign(id * 2, a, mid);
		sign(id * 2 + 1, mid + 1, b);
		ns[id].tot = (ns[id * 2].tot + ns[id * 2 + 1].tot) % p;
	}
	else
	{
		ns[id].tot = nums[a];
	}
}
void pushdown(int id) //向下传递lazytag 并更新节点tot
{
	long long plus = ns[id].lazyp, mul = ns[id].lazym;
	ns[id].tot = (ns[id].tot * mul + plus * (ns[id].r - ns[id].l + 1)) % p;
	ns[id].lazyp = 0, ns[id].lazym = 1;
	//先乘后加 如果新增加则直接加 如果新增乘则将加的部分也乘一下
	if (ns[id].l != ns[id].r) //向左右子节点传递lazytag
	{
		ns[id * 2].lazym = mul * ns[id * 2].lazym % p;
		ns[id * 2 + 1].lazym = mul * ns[id * 2 + 1].lazym % p;
		ns[id * 2].lazyp = (plus + (ns[id * 2].lazyp * mul)) % p;
		ns[id * 2 + 1].lazyp = (plus + (ns[id * 2 + 1].lazyp * mul)) % p;
	}
}
void make(int id, int a, int b)
{
	pushdown(id);
	if (ns[id].l == a && ns[id].r == b) //当前区域是目标区域
	{
		if (type == 1)
		{
			ns[id].tot = k * ns[id].tot % p;
			if (a != b)
			{
				ns[id * 2].lazym = k * ns[id * 2].lazym % p;
				ns[id * 2 + 1].lazym = k * ns[id * 2 + 1].lazym % p;
				ns[id * 2].lazyp = k * ns[id * 2].lazyp % p;
				ns[id * 2 + 1].lazyp = k * ns[id * 2 + 1].lazyp % p;
			}
		}
		else if (type == 2)
		{
			ns[id].tot = (ns[id].tot + k * (b - a + 1)) % p;
			if (a != b) //处理子树的lazytag a!=b说明存在子树
			{
				ns[id * 2].lazyp = (k + ns[id * 2].lazyp) % p;
				ns[id * 2 + 1].lazyp = (k + ns[id * 2 + 1].lazyp) % p;
			}
		}
		else
		{
			all = (ns[id].tot + all) % p;
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
		if (type != 3) //值有增减才更新tot
		{
			int tot1 = (ns[id * 2].tot * ns[id * 2].lazym + ns[id * 2].lazyp * (ns[id * 2].r - ns[id * 2].l + 1)) % p;
			int tot2 = (ns[id * 2 + 1].tot * ns[id * 2 + 1].lazym + ns[id * 2 + 1].lazyp * (ns[id * 2 + 1].r - ns[id * 2 + 1].l + 1)) % p;
			ns[id].tot = (tot1 + tot2) % p;
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) //读入
	{
		cin >> nums[i];
	}
	sign(1, 1, n);				 //标记
	for (int i = 1; i <= m; i++) //处理
	{
		int x, y;
		cin >> type >> x >> y;
		if (type != 3) //修改
		{
			cin >> k;
		}
		all = 0;
		make(1, x, y); //处理
		if (type == 3) //查询
		{
			cout << all % p << endl;
		}
	}
	return 0;
}