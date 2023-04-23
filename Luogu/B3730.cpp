#include <algorithm>
#include <iostream>
using namespace std;
int pos, vis[1000005], prim[1000005];
int main()
{
	int now, mint = 0x3f3f3f3f, ans = 0;
	scanf("%d", &now);
	for (int i = 2; i <= 99999; i++)
	{
		if (vis[i] == 0)
		{
			prim[++pos] = i;
		}
		for (int j = 1; j <= pos && i * prim[j] <= 99999; j++)
		{
			vis[i * prim[j]] = 1;
			if (i % prim[j] == 0)
			{
				break;
			}
		}
	}
	for (int i = 1; i <= pos; i++)
	{
		int a = now, b = prim[i], t = 0;
		while (a || b)
		{
			int x = abs(a % 10 - b % 10);
			t += min(x, 10 - x);
			a /= 10, b /= 10;
		}
		if (t <= mint)
		{
			mint = t, ans = prim[i];
		}
	}
	printf("%05d\n", ans);
	return 0;
}