#include <cstdio>
#include <algorithm>
using namespace std;
int read();
int w[10005];
int main()
{
	int n = read(), m = read(), ans = 0;
	for (int i = 1; i <= n; i++)
	{
		w[i] = read();
		w[i] *= 2;
	}
	for (int i = 1; i <= m; i++)
	{
		int a = read(), b = read(), c = read();
		w[a] += c;
		w[b] += c;
	}
	sort(w + 1, w + 1 + n);
	for (int i = n; i >= 1; i -= 2)
	{
		ans += (w[i] - w[i - 1]);
	}
	printf("%d", ans / 2);
	return 0;
}
int read() //* 快读
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