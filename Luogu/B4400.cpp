#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int v, x, y, ans = 2e9, sta[205][205][205];
void dfs(int a, int b, int c, int la, int lb, int lc, int step)
{
	sta[a][b][c] = min(sta[a][b][c], step);
	if (a == v / 2 || b == v / 2 || c == v / 2)
	{
		ans = min(ans, step);
		return;
	}
	int na, nb, nc;
	na = max(0, a + b - x), nb = min(x, a + b); // a->b
	if ((na != la || nb != lb) && step + 1 < sta[na][nb][c])
	{
		dfs(na, nb, c, a, b, c, step + 1);
	}
	na = max(0, a + c - y), nc = min(y, a + c); // a->c
	if ((na != la || nc != lc) && step + 1 < sta[na][b][nc])
	{
		dfs(na, b, nc, a, b, c, step + 1);
	}
	nb = max(0, b + c - y), nc = min(y, b + c); // b->c
	if ((nb != lb || nc != lc) && step + 1 < sta[a][nb][nc])
	{
		dfs(a, nb, nc, a, b, c, step + 1);
	}
	nb = max(0, a + b - v), na = min(v, a + b); // b->a
	if ((na != la || nb != lb) && step + 1 < sta[na][nb][c])
	{
		dfs(na, nb, c, a, b, c, step + 1);
	}
	nc = max(0, a + c - v), na = min(v, a + c); // c->a
	if ((na != la || nc != lc) && step + 1 < sta[na][b][nc])
	{
		dfs(na, b, nc, a, b, c, step + 1);
	}
	nc = max(0, b + c - x), nb = min(x, b + c); // c->b
	if ((nb != lb || nc != lc) && step + 1 < sta[a][nb][nc])
	{
		dfs(a, nb, nc, a, b, c, step + 1);
	}
}
int main()
{
	cin >> v >> x >> y;
	if (v % 2 == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	memset(sta, 0x3f, sizeof(sta));
	dfs(v, 0, 0, 0, 0, 0, 0);
	cout << (ans == 2e9 ? -1 : ans) << endl;
	return 0;
}