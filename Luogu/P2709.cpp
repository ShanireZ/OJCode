#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[50005], p[50005], ts[50005], ans[50005];
struct Quest
{
	int l, r, id;
};
Quest quest[50005];
bool cmp(Quest a, Quest b)
{
	if (p[a.l] == p[b.l])
	{
		return a.r < b.r;
	}
	return p[a.l] < p[b.l];
}
void add(int x, int p)
{
	int num = a[x];
	ans[p] -= ts[num] * ts[num];
	ts[num]++;
	ans[p] += ts[num] * ts[num];
}
void sub(int x, int p)
{
	int num = a[x];
	ans[p] -= ts[num] * ts[num];
	ts[num]--;
	ans[p] += ts[num] * ts[num];
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int block = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[i] = i / block;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> quest[i].l >> quest[i].r;
		quest[i].id = i;
	}
	sort(quest + 1, quest + 1 + m, cmp);
	int st = 1, ed = 0;
	for (int i = 1; i <= m; i++)
	{
		int now = quest[i].id;
		int pre = quest[i - 1].id;
		ans[now] = ans[pre];
		while (quest[i].l < st)
		{
			add(--st, now);
		}
		while (quest[i].l > st)
		{
			sub(st++, now);
		}
		while (quest[i].r > ed)
		{
			add(++ed, now);
		}
		while (quest[i].r < ed)
		{
			sub(ed--, now);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}