#include <cstdio>
#include <algorithm>
using namespace std;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch > '9' || ch < '0')
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
struct Node
{
	//lc rc左右子节点编号 dis距离外节点距离 fa上级 v领导力 sal薪水
	int lc, rc, dis, fa, v, sal;
};
Node ns[100005];
int n, m, root[100005];				//堆顶编号
long long sum[100005], cnt[100005]; //堆内薪水和 堆内节点个数
int merge(int a, int b)				//左偏树合并
{
	if (a == 0 || b == 0)
	{
		return a + b;
	}
	if (ns[a].sal < ns[b].sal) //薪水为权值 大根堆
	{
		swap(a, b);
	}
	ns[a].rc = merge(ns[a].rc, b);
	if (ns[ns[a].lc].dis < ns[ns[a].rc].dis) //维护左偏特性
	{
		swap(ns[a].lc, ns[a].rc);
	}
	ns[a].dis = ns[ns[a].rc].dis + 1;
	return a;
}
int main()
{
	n = read(), m = read();
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int b = read(), c = read(), l = read();
		root[i] = i, cnt[i] = 1, sum[i] = c;
		ns[i].fa = b, ns[i].sal = c, ns[i].v = l;
		if (sum[i] <= m)
		{
			ans = max(ans, cnt[i] * ns[i].v);
		}
	}
	// 每个忍者上级的编号必然小于其编号 1号必为Master
	for (int i = n; i > 1; i--) //将每个堆和其上级合并
	{
		int fa = ns[i].fa;
		root[fa] = merge(root[i], root[fa]);
		cnt[fa] += cnt[i], sum[fa] += sum[i];
		while (sum[fa] > m)
		{
			sum[fa] -= ns[root[fa]].sal;
			cnt[fa]--;
			root[fa] = merge(ns[root[fa]].lc, ns[root[fa]].rc);
		}
		ans = max(ans, cnt[fa] * ns[fa].v);
	}
	printf("%lld\n", ans);
	return 0;
}
