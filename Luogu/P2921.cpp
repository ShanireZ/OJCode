#include <iostream>
using namespace std;
struct Node
{
	int to, way, step; //to-目标 way-该点能得到糖果数目 step-该点在当前路径上第几步访问过
};
Node nodes[100005];
int pos; //记录当前环的环头
void dfs(int x, int step)
{
	if (nodes[x].way != 0)
	{
		return;
	}
	if (nodes[x].step != 0) //走到之前走过的点说明出现了环
	{
		nodes[x].way = step - nodes[x].step;
		pos = x;
		return;
	}
	nodes[x].step = step;
	dfs(nodes[x].to, step + 1);
	if (pos) //pos=0说明当前是链状 pos!=0说明当前是环状
	{
		if (x == pos)
		{
			pos = 0;
		}
		else
		{
			nodes[x].way = nodes[pos].way; //环内得到糖果数都一致
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