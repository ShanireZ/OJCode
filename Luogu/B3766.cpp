#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
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
vector<int> a[2][10005];
int main()
{
	int n = read(), t = read(), lim = 1;
	for (int i = 1; i <= n; i++)
	{
		a[1][1].push_back(read());
	}
	for (int i = 1; i <= t; i++)
	{
		int k = read(), from = i % 2, fpos = 1;
		int to = 1 - from, tpos = 1;
		while (fpos <= lim)
		{
			for (int x : a[from][fpos])
			{
				a[to][tpos].push_back(x);
				tpos = (tpos + 1 > k) ? 1 : tpos + 1;
			}
			a[from][fpos++].clear();
		}
		lim = k;
	}
	int from = 1 - t % 2, fpos = 1;
	while (fpos <= lim)
	{
		for (int x : a[from][fpos])
		{
			printf("%d ", x);
		}
		fpos++;
	}
	return 0;
}