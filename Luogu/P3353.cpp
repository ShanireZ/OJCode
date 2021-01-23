#include <cstdio>
#include <algorithm>
using namespace std;
int b[100005];
int read();
int main()
{
	int n = read(), w = read(), maxb = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		b[x] += read();
	}
	for (int i = 1; i <= 100000; i++)
	{
		b[i] += b[i - 1];
		if (i >= w)
		{
			maxb = max(maxb, b[i] - b[i - w]);
		}
	}
	printf("%d", maxb);
	return 0;
}
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