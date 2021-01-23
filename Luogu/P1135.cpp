#include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int up, down, step;
};
Node ns[205];
queue<int> q;
int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		ns[i].up = i + tmp;
		if (ns[i].up > n)
		{
			ns[i].up = -1;
		}
		ns[i].down = i - tmp;
		if (ns[i].down < 1)
		{
			ns[i].down = -1;
		}
		ns[i].step = -1;
	}
	q.push(a);
	ns[a].step = 0;
	while (q.size())
	{
		int from = q.front();
		int to1 = ns[from].up, to2 = ns[from].down;
		if (to1 != -1 && ns[to1].step == -1)
		{
			q.push(to1);
			ns[to1].step = ns[from].step + 1;
		}
		if (to2 != -1 && ns[to2].step == -1)
		{
			q.push(to2);
			ns[to2].step = ns[from].step + 1;
		}
		q.pop();
	}
	if (a == b)
	{
		cout << 0;
	}
	else
	{
		cout << ns[b].step;
	}
	return 0;
}