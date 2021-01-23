#include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int lc, rc, lv;
};
Node nodes[1000005];
queue<int> q;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nodes[i].lc >> nodes[i].rc;
	}
	nodes[1].lv = 1;
	q.push(1);
	int maxh = 0;
	while (q.size())
	{
		int from = q.front();
		q.pop();
		int to1 = nodes[from].lc, to2 = nodes[from].rc;
		nodes[to1].lv = nodes[to2].lv = nodes[from].lv + 1;
		if (to1 != 0)
		{
			maxh = max(maxh, nodes[to1].lv);
			q.push(to1);
		}
		if (to2 != 0)
		{
			maxh = max(maxh, nodes[to2].lv);
			q.push(to2);
		}
	}
	cout << maxh;
	return 0;
}