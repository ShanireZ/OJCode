#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> all;
const int maxs = 5e4 + 5;
int ts[maxs], a[maxs], l[maxs], r[maxs];
int read() //快读
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
int main()
{
	int n = read(), k = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		all.push_back(a[i]);
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	for (int i = 1; i <= n; i++)
	{
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		ts[id]++;
	}
	int st = 0, tot = 0;
	for (int i = 0; i < all.size(); i++) //i及右侧长度
	{
		if (i - 1 >= 0)
		{
			tot -= ts[i - 1];
		}
		while (st < all.size())
		{
			if (all[st] - all[i] <= k)
			{
				tot += ts[st];
			}
			else
			{
				break;
			}
			st++;
		}
		r[i] = tot;
	}
	st = 0, tot = 0;
	for (int i = 0; i < all.size(); i++) //i左侧长度
	{
		if (i - 1 >= 0)
		{
			tot += ts[i - 1];
		}
		while (st < i - 1)
		{
			if (all[i - 1] - all[st] > k)
			{
				tot -= ts[st];
			}
			else
			{
				break;
			}
			st++;
		}
		l[i] = tot;
	}
	int maxn = 0, maxl = 0;
	for (int i = 0; i < all.size(); i++)
	{
		maxl = max(maxl, l[i]);
		int maxr = 0;
		for (int j = i; j < all.size(); j++)
		{
			maxr = max(maxr, r[j]);
		}
		maxn = max(maxn, maxl + maxr);
	}
	printf("%d", maxn);
	return 0;
}