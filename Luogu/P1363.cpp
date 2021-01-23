#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
	int x, y, check, v, id1, id2;
	//x为节点行号 y为节点列号
	//check为之前是否已经路过
	//v为该节点是否可通行 1为. 2为S 0为#
	//id1 id2为当前地图的编号 id1为纵坐标编号 id2为横坐标编号 左上跨图- 右下跨图+
};
Node nodes[1505][1505];
queue<Node> way;
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //右 左 下 上移动时坐标变化
int main()
{
	int n, m;
	while (cin >> n >> m) //每组样例读入
	{
		int trig = 0;				 //标记是否可走出迷宫
		way = queue<Node>();		 //队列清空
		int startX, startY;			 //S所在位置作为起始
		for (int i = 1; i <= n; i++) //读入地图
		{
			for (int j = 1; j <= m; j++)
			{
				char tmp;
				cin >> tmp;
				if (tmp == '.')
				{
					nodes[i][j].v = 1;
				}
				else if (tmp == 'S')
				{
					nodes[i][j].v = 2;
					startX = i;
					startY = j;
				}
				else
				{
					nodes[i][j].v = 0;
				}
				nodes[i][j].check = 0; //状态清空
				nodes[i][j].x = i;
				nodes[i][j].y = j;
			}
		}

		int map1 = 1, map2 = 1; //当前所在地图编号
		nodes[startX][startY].check = 1;
		nodes[startX][startY].id1 = map1;
		nodes[startX][startY].id2 = map2;
		way.push(nodes[startX][startY]); //队首入队
		while (way.size() != 0)
		{
			//取出队首的位置和所在地图编号
			int x = way.front().x;
			int y = way.front().y;
			map1 = way.front().id1;
			map2 = way.front().id2;
			for (int i = 0; i < 4; i++) //以当前队首为出发点开始上下左右移动
			{
				//求出移动后位置的坐标及地图编号
				int newX = x + pos[i][0];
				int newY = y + pos[i][1];
				int newM1 = map1;
				int newM2 = map2;
				if (newX > n)
				{
					newX -= n;
					newM1++;
				}
				else if (newX < 1)
				{
					newX += n;
					newM1--;
				}
				if (newY > m)
				{
					newY -= m;
					newM2++;
				}
				else if (newY < 1)
				{
					newY += m;
					newM2--;
				}
				//判断是否为#不可同行
				if (nodes[newX][newY].v == 0)
				{
					continue;
				}
				//判断之前该点是否路过
				if (nodes[newX][newY].check)
				{
					//如果在不同地图内都路过了同一个点，那么说明可以无限行进走出迷宫
					if (nodes[newX][newY].id1 != newM1 || nodes[newX][newY].id2 != newM2)
					{
						trig = 1;
						break;
					}
				}
				else //该点之前没路过，加入队列
				{
					nodes[newX][newY].check = 1;
					nodes[newX][newY].id1 = newM1;
					nodes[newX][newY].id2 = newM2;
					way.push(nodes[newX][newY]);
				}
			}
			way.pop();
			if (trig)
			{
				break;
			}
		}
		if (trig)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}