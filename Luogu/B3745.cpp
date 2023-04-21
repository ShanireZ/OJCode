#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int read(), f[105], p[105], ff[105];
multiset<int> s[105];
int main()
{
	int n = read(), m = read(), r = read(), cnt = n;
	for (int i = 1; i <= n; i++)
	{
		f[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		p[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		ff[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		s[ff[i]].insert(read());
	}
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		auto pos = s[f[x]].upper_bound(p[x]);
		if (pos != s[f[x]].end())
		{
			s[f[x]].erase(pos), cnt--;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
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