#include <cstring>
#include <iostream>
using namespace std;
char s[10005];
int main()
{
	ios::sync_with_stdio(false);
	int t, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s %d", s, &k);
		int len = strlen(s) - 1;
		if (s[0] == '0')
		{
			puts("-1\n");
			continue;
		}
		while (k--)
		{
			putchar('9');
		}
		while (len--)
		{
			putchar('0');
		}
		putchar('\n');
	}
	return 0;
}