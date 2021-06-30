#include <cstdio>
using namespace std;
long long ans[25][25][25];
long long w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}
	if (ans[a][b][c])
	{
		return ans[a][b][c];
	}
	else if (a < b && b < c)
	{
		return ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		return ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (a != -1 || b != -1 || c != -1)
	{
		printf("w(%d, %d, %d) = %lld\n", a, b, c, w(a, b, c));
		scanf("%d %d %d", &a, &b, &c);
	}
	return 0;
}