#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
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
int n, maxt, d[10005];
bool check(int k)
{
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= k; i++)
	{
		q.push(d[i]);
	}
	int pos = k + 1, t = 0;
	while (q.size())
	{
		t += q.top() - t;
		//t = q.top();
		q.pop();
		if (pos <= n)
		{
			q.push(d[pos] + t);
			pos++;
		}
	}
	if (t <= maxt)
	{
		return true;
	}
	return false;
}
int main()
{
	n = read(), maxt = read();
	for (int i = 1; i <= n; i++)
	{
		d[i] = read();
	}
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("%d\n", l);
	return 0;
}