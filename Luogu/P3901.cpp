#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int a[100005];	  //原数列
int area[100005]; //每个数所在块
int ans[100005];  //每个询问是否满足
int ts[100005];	  //每个数出现次数
set<int> more;	  //重复的数有哪些
struct Quest
{
	int l, r, id;
};
Quest quest[100005];
bool cmp(Quest a, Quest b) //分块后按块排序 同块按r排序
{
	if (area[a.l] == area[b.l])
	{
		return a.r < b.r;
	}
	return area[a.l] < area[b.l];
}
void sub(int x) //减元素x
{
	int num = a[x];
	ts[num]--;
	if (ts[num] == 1)
	{
		more.erase(num);
	}
}
void add(int x) //加元素x
{
	int num = a[x];
	ts[num]++;
	if (ts[num] > 1)
	{
		more.insert(num);
	}
}
int check() //检测是否重复
{
	if (more.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n, q;
	cin >> n >> q;
	int m = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		area[i] = i / m;
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> quest[i].l >> quest[i].r;
		quest[i].id = i;
	}
	sort(quest + 1, quest + 1 + q, cmp);
	int st = 1, ed = 0;
	for (int i = 1; i <= q; i++)
	{
		while (quest[i].l < st)
		{
			add(--st);
		}
		while (quest[i].l > st)
		{
			sub(st++);
		}
		while (quest[i].r > ed)
		{
			add(++ed);
		}
		while (quest[i].r < ed)
		{
			sub(ed--);
		}
		ans[quest[i].id] = check();
	}
	for (int i = 1; i <= q; i++)
	{
		if (ans[i] == 1)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}