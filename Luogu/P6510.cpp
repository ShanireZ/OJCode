#include <iostream>
using namespace std;
#define MX 100005
int h[MX], l[MX], r[MX], s[MX], ans, pos, n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	pos = 0, s[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (pos && h[s[pos]] < h[i])
		{
			pos--;
		}
		l[i] = s[pos];
		s[++pos] = i;
	}
	pos = 0, s[0] = n + 1;
	for (int i = n; i >= 1; i--)
	{
		while (pos && h[s[pos]] > h[i])
		{
			pos--;
		}
		r[i] = s[pos];
		s[++pos] = i;
	}
	for (int i = n; i >= 1; i--) // 枚举终点
	{
		for (int j = l[i] + 1; j < i; j++) // 枚举该终点的所有起点
		{
			if (r[j] > i)
			{
				ans = max(ans, i - j + 1);
				break;
			}
		}
		if (ans >= i)
		{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}