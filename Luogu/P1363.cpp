#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
	int x, y, check, v, id1, id2;
	//x為節點行號 y為節點列號
	//check為之前是否已經路過
	//v為該節點是否可通行 1為. 2為S 0為#
	//id1 id2為當前地圖的編號 id1為縱座標編號 id2為橫座標編號 左上跨圖- 右下跨圖+
};
Node nodes[1505][1505];
queue<Node> way;
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //右 左 下 上移動時座標變化
int main()
{
	int n, m;
	while (cin >> n >> m) //每組範例讀入
	{
		int trig = 0;				 //標記是否可走出迷宮
		way = queue<Node>();		 //佇列清空
		int startX, startY;			 //S所在位置作為起始
		for (int i = 1; i <= n; i++) //讀入地圖
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
				nodes[i][j].check = 0; //狀態清空
				nodes[i][j].x = i;
				nodes[i][j].y = j;
			}
		}

		int map1 = 1, map2 = 1; //當前所在地圖編號
		nodes[startX][startY].check = 1;
		nodes[startX][startY].id1 = map1;
		nodes[startX][startY].id2 = map2;
		way.push(nodes[startX][startY]); //隊首入隊
		while (way.size() != 0)
		{
			//取出隊首的位置和所在地圖編號
			int x = way.front().x;
			int y = way.front().y;
			map1 = way.front().id1;
			map2 = way.front().id2;
			for (int i = 0; i < 4; i++) //以當前隊首為出發點開始上下左右移動
			{
				//求出移動後位置的座標及地圖編號
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
				//判斷是否為#不可同行
				if (nodes[newX][newY].v == 0)
				{
					continue;
				}
				//判斷之前該點是否路過
				if (nodes[newX][newY].check)
				{
					//如果在不同地圖內都路過了同一個點，那麼說明可以無限行進走出迷宮
					if (nodes[newX][newY].id1 != newM1 || nodes[newX][newY].id2 != newM2)
					{
						trig = 1;
						break;
					}
				}
				else //該點之前沒路過，加入佇列
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