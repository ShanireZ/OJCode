#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], read();
int main()
{
	int n = read(), m = read(), ans = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	for (int i = 1; i <= m; i++) // 枚舉輪數
	{
		int d = read();
		for (int j = 1; j <= d; j++) // 枚舉每個組
		{
			for (int k = j; k <= n; k += d) // 枚舉組內的每個元素
			{
				ans++;
				for (int x = k; x - d > 0 && a[x] < a[x - d]; x -= d) // 插入排序
				{
					swap(a[x], a[x - d]), ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
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