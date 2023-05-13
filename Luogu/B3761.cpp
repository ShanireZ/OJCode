#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string cmd;
int base[16], fin[16], r[5] = {0, 1, 4, 9, 16}, u[5] = {16, 9, 4, 1, 0};
void multimx(int pre[16], int suf[16])
{
	int tmp[16] = {0};
	for (int i = 0; i < 16; i++)
	{
		tmp[i] = pre[suf[i]];
	}
	for (int i = 0; i < 16; i++)
	{
		pre[i] = tmp[i];
	}
}
int main()
{
	int a, b;
	cin >> cmd >> a >> b;
	for (int i = 0; i < 16; i++)
	{
		base[i] = i;
	}
	for (int i = 0; i < (int)cmd.size(); i += 2) // 单次全部翻转
	{
		int x = cmd[i + 1] - '0';
		int id = x / 2 + 1;
		if (cmd[i] == 'R')
		{
			int last = r[id] - 1, now = r[id - 1];
			while (x--)
			{
				swap(base[last], base[now]);
				now++;
			}
		}
		else if (cmd[i] == 'U')
		{
			int last = u[id], now = x + 8, ex = 5;
			while (x--)
			{
				swap(base[last], base[now]);
				now--;
				if (x % 2 == 1)
				{
					now -= ex, ex -= 2;
				}
			}
		}
		else
		{
			int last = 16 - x, now = u[id - 1] - 1, ex = 10 - x;
			while (x--)
			{
				swap(base[last], base[now]);
				now--;
				if (x % 2 == 0)
				{
					now += ex, ex += 2;
				}
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		fin[i] = base[i];
	}
	while (b--) // 计算a^b次翻转
	{
		for (int i = 2; i <= a; i++) // a个a^x-1次=a^x次
		{
			multimx(fin, base);
		}
		for (int i = 0; i < 16; i++)
		{
			base[i] = fin[i];
		}
	}
	for (int i = 0; i < 16; i++)
	{
		cout << char(fin[i] + 'A');
	}
	return 0;
}