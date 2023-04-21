#include <cstring>
#include <iostream>
using namespace std;
int cnt[100005][30], read();
char s[1000005];
int main()
{
	ios::sync_with_stdio(false);
	int n = read(), q = read();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < (int)strlen(s); j++)
		{
			cnt[i][s[j] - 'a']++;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int op = read(), x = read(), y = read();
		if (op == 1)
		{
			for (int j = 0; j < 26; j++)
			{
				cnt[y][j] += cnt[x][j];
			}
		}
		else
		{
			for (int j = 0; j < 26; j++)
			{
				if (cnt[x][j] != cnt[y][j])
				{
					op = 0;
					break;
				}
			}
			printf(op == 2 ? "Yes\n" : "No\n");
		}
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