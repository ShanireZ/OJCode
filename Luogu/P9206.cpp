#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], tmp[100005], read();
int main()
{
	int n = read(), m = read(), ans = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	for (int i = 1; i <= m; i++) // 枚举轮数
	{
		int d = read();
		for (int j = 1; j <= d; j++) // 枚举每个组
		{
			int pos = 0;
			for (int k = j; k <= n; k += d) // 枚举组内的每个元素
			{
				tmp[++pos] = a[k], ans++;
				for (int x = pos; x > 1 && tmp[x] < tmp[x - 1]; x--) // 插入排序
				{
					swap(tmp[x], tmp[x - 1]), ans++;
				}
			}
			pos = 0;
			for (int k = j; k <= n; k += d)
			{
				a[k] = tmp[++pos];
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