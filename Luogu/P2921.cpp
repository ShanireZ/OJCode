#include <iostream>
using namespace std;
struct Node
{
	int to, way, step; //to-目標 way-該點能得到糖果數目 step-該點在當前路徑上第幾步訪問過
};
Node nodes[100005];
int pos; //記錄當前環的環頭
void dfs(int x, int step)
{
	if (nodes[x].way != 0)
	{
		return;
	}
	if (nodes[x].step != 0) //走到之前走過的點說明出現了環
	{
		nodes[x].way = step - nodes[x].step;
		pos = x;
		return;
	}
	nodes[x].step = step;
	dfs(nodes[x].to, step + 1);
	if (pos) //pos=0說明當前是鏈狀 pos!=0說明當前是環狀
	{
		if (x == pos)
		{
			pos = 0;
		}
		else
		{
			nodes[x].way = nodes[pos].way; //環內得到糖果數都一致
		}
	}
	else
	{
		nodes[x].way = nodes[nodes[x].to].way + 1;
	}
	nodes[x].step = 0;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nodes[i].to;
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, 1);
		cout << nodes[i].way << endl;
	}
	return 0;
}