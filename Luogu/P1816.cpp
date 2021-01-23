#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int cnt[100005][20];
int read();
int main()
{
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		cnt[i][0] = read();
	}
	for (int k = 1; k <= log2(n); k++)
	{
		for (int i = 1; i + pow(2, k) - 1 <= n; i++) //不能越界
		{
			int mid = i + pow(2, k - 1); //后半部分的开头
			cnt[i][k] = min(cnt[i][k - 1], cnt[mid][k - 1]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a = read(), b = read();
		int x = log2(b - a + 1);
		int mid = b - pow(2, x) + 1;
		printf("%d ", min(cnt[a][x], cnt[mid][x]));
	}
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