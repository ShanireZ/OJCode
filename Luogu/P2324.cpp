#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int mins, trig; //* mins最短步数 trig是否达成
int now[7][7];	//* 当前状态
int ans[7][7] = {{0},
				 {0, 1, 1, 1, 1, 1},
				 {0, 0, 1, 1, 1, 1},
				 {0, 0, 0, 5, 1, 1},
				 {0, 0, 0, 0, 0, 1},
				 {0, 0, 0, 0, 0, 0}}; //* 目标状态
int mx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int my[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool check() //* 检查是否已经到达目标状态
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (now[i][j] != ans[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
//* step为从起点到当前状态的步数
//* cnt为当前错误位置的数字个数---至少需要几步才能到达目标状态
//* 如果cnt + step > mins 说明步数肯定超出 剪枝处理
bool astar(int step)
{
	int cnt = 0;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (now[i][j] != ans[i][j])
			{
				if (cnt + step > mins)
				{
					return false;
				}
				cnt++; //* cnt个错误位置数字最少需要cnt-1步 所以先判断后自增
			}
		}
	}
	return true;
}
void dfs(int x, int y, int step, int pre)
{
	if (check()) //* 当前状态是否完成目标
	{
		trig = 1;
		return;
	}
	if (astar(step) == false) //* 当前是否需要剪枝
	{
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int nx = x + mx[i], ny = y + my[i];
		//* i+pre==7表示往返行进 回到了上一位置
		//* 这样就不需要额外的状态数组了
		if (nx < 1 || nx > 5 || ny < 1 || ny > 5 || i + pre == 7)
		{
			continue;
		}
		swap(now[nx][ny], now[x][y]);
		dfs(nx, ny, step + 1, i);
		swap(now[nx][ny], now[x][y]);
		if (trig)
		{
			return;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int sx, sy;
		mins = 0, trig = 0;
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				char ch;
				cin >> ch;
				if (ch == '*')
				{
					now[i][j] = 5;
					sx = i, sy = j;
				}
				else
				{
					now[i][j] = ch - '0';
				}
			}
		}
		while (mins <= 15)
		{
			dfs(sx, sy, 0, -1);
			if (trig)
			{
				break;
			}
			mins++; //* 从0开始枚举最小步数 可用二分优化
		}
		if (trig)
		{
			cout << mins << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}