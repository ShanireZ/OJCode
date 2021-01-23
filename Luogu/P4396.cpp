#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], p[maxn], ts[maxn], tot[maxn], cnt[maxn], ans[maxn][2], block;
//a原数列  p每个数所在块 block块大小 ans存储输出所需答案
//ts每个数出现次数 tot每个块内的数字数量 cnt每个块内的数字种类数量
//ps.tot cnt按块存储可以不用开这么大
struct Quest
{
	int l, r, id, a, b;
};
Quest quest[maxn];
bool cmp(Quest a, Quest b)
{
	if (p[a.l] == p[b.l])
	{
		return a.r < b.r;
	}
	return p[a.l] < p[b.l];
}
void add(int x)
{
	int num = a[x];
	int pid = p[num];
	ts[num]++;
	tot[pid]++;
	if (ts[num] == 1)
	{
		cnt[pid]++;
	}
}
void sub(int x)
{
	int num = a[x];
	int pid = p[num];
	ts[num]--;
	tot[pid]--;
	if (ts[num] == 0)
	{
		cnt[pid]--;
	}
}
void makeans(int a, int b, int id)
{
	if (p[a] == p[b]) //如果a和b在同一块
	{
		for (int i = a; i <= b; i++)
		{
			ans[id][0] += ts[i];
			if (ts[i])
			{
				ans[id][1]++;
			}
		}
	}
	else
	{
		for (int i = a; i <= (p[a] + 1) * block - 1; i++) //头部块
		{
			ans[id][0] += ts[i];
			if (ts[i])
			{
				ans[id][1]++;
			}
		}
		for (int i = p[b] * block; i <= b; i++) //尾部块
		{
			ans[id][0] += ts[i];
			if (ts[i])
			{
				ans[id][1]++;
			}
		}
		for (int i = p[a] + 1; i <= p[b] - 1; i++) //中间整块处理
		{
			ans[id][0] += tot[i];
			ans[id][1] += cnt[i];
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	block = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[i] = i / block;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> quest[i].l >> quest[i].r >> quest[i].a >> quest[i].b;
		quest[i].id = i;
	}
	sort(quest + 1, quest + 1 + m, cmp);
	int st = 1, ed = 0;
	for (int i = 1; i <= m; i++)
	{
		while (st > quest[i].l)
		{
			add(--st);
		}
		while (st < quest[i].l)
		{
			sub(st++);
		}
		while (ed < quest[i].r)
		{
			add(++ed);
		}
		while (ed > quest[i].r)
		{
			sub(ed--);
		}
		makeans(quest[i].a, quest[i].b, quest[i].id);
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	return 0;
}