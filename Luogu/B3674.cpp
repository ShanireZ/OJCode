#include <cstdio>
using namespace std;
int main()
{
	char ch;
	int now = 0;
	while ((ch = getchar()) != EOF)
	{
		int t = 0;
		if (ch >= 'A' && ch <= 'Z')
		{
			t = 1;
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			t = 2;
		}
		if (t == 0)
		{
			printf(" "), now = 0;
		}
		else
		{
			now++;
			if (now % 2 == 1)
				printf("%c", (t == 1) ? ch : ch - 32);
			else
				printf("%c", (t == 2) ? ch : ch + 32);
		}
	}
	return 0;
}