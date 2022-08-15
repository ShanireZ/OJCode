#include <algorithm>
#include <cstdio>
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
int s[366];
int main()
{
	for (int i = 2; i < 365; i++)
	{
		s[i] = -1;
	}
	int n = read();
	s[1] = read(), s[3] = read(), s[7] = read(), s[30] = read(), s[120] = read(), s[365] = read();
	for (int i = 2; i < 365; i++)
	{
		if (s[i] == -1)
		{
			s[i] = s[i - 1];
		}
	}
	int cnt = 0, tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		cnt = (x == 1) ? cnt + 1 : 0;
		tot += (cnt > 365) ? s[365] : s[cnt];
	}
	printf("%d\n", tot);
	return 0;
}