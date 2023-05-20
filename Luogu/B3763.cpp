#include <iostream>
using namespace std;
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
int main()
{
	int tot = 0;
	for (int i = 1; i <= 8; i++)
	{
		tot += read();
	}
	if (tot >= 80)
	{
		int now = 0;
		for (int i = 1; i <= 4; i++)
		{
			now += read();
		}
		tot += now;
		if (now >= 40)
		{
			for (int i = 1; i <= 3; i++)
			{
				tot += read();
			}
		}
	}
	cout << tot << "\n";
	return 0;
}