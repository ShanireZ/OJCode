#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int od[1005][1005], n, g;
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
set<int> s;
void dfs(int x, int y)
{
	od[x][y] = -1;
	int ok = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + ms[i][0], ny = y + ms[i][1];
		if (nx < 1 || nx > n || ny < 1 || ny > n || od[nx][ny] == -1)
		{
			continue;
		}
		if (od[nx][ny] == 0)
		{
			ok = 0;
			continue;
		}
		dfs(nx, ny);
	}
	if (ok)
	{
		s.insert(g);
	}
}
int main()
{
	cin >> n;
	char c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> c;
			od[i][j] = (c == '#');
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (od[i][j] == 1)
			{
				g++;
				dfs(i, j);
			}
		}
	}
	cout << g - s.size() << endl;
	return 0;
}