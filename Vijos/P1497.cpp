#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int all[55][55];
string pic[500];
int main()
{
	//每个正方形的每行 从下至上
	string block[6] = {"+---+", "|   |/", "|   | +", "+---+ |", "/   /|", "+---+"};
	int m, n, high = 0;		//最高
	int maxX = 0, maxY = 0; //图形高度和宽度
	cin >> m >> n;
	for (int i = m - 1; i >= 0; i--) //从上至下读入
	{
		for (int j = 0; j < n; j++)
		{
			cin >> all[i][j];
			high = max(high, all[i][j]);
		}
	}
	for (int i = 0; i < 500; i++) //先填满.
	{
		pic[i].append(500, '.');
	}
	//从最上行开始逐列逐个高度生成方块 后续的可直接替换之前的图形
	for (int i = m - 1; i >= 0; i--) //从最上一行开始
	{
		for (int j = 0; j < n; j++) //逐列
		{
			for (int k = 0; k < high; k++) //逐个高度
			{
				int tmpX = i * 2 + k * 3; //该行列高的起始X坐标
				int tmpY = j * 4 + i * 2; //该行列高的起始Y坐标
				if (all[i][j] > k)		  //如果需要加一个块 那就用块替换之前的图形
				{
					for (int x = 0; x < 6; x++)
					{
						if (x == 0)
						{
							pic[tmpX + x].replace(tmpY, 5, block[x]);
						}
						else if (x == 1)
						{
							pic[tmpX + x].replace(tmpY, 6, block[x]);
						}
						else if (x == 2 || x == 3)
						{
							pic[tmpX + x].replace(tmpY, 7, block[x]);
						}
						else if (x == 4)
						{
							pic[tmpX + x].replace(tmpY + 1, 6, block[x]);
						}
						else
						{
							pic[tmpX + x].replace(tmpY + 2, 5, block[x]);
						}
					}
					//寻找最终图形的边界
					maxX = max(tmpX + 5, maxX);
					maxY = max(tmpY + 6, maxY);
				}
			}
		}
	}
	for (int i = maxX; i >= 0; i--)
	{
		cout << pic[i].substr(0, maxY + 1) << endl;
	}
	return 0;
}