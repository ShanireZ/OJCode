#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct Hole
{
	long long x, y, z;
};
Hole hole[1005];
int g[1005];
int up[1005];
int down[1005];
int dfn(int x)
{
	if (g[x] != x)
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
int main()
{
	int t;
	cin >> t;
	for (int times = 1; times <= t; times++)
	{
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));
		long long n, h, r;
		cin >> n >> h >> r;
		for (int i = 1; i <= n; i++)
		{
			g[i] = i;
			cin >> hole[i].x >> hole[i].y >> hole[i].z;
			if (hole[i].z <= r)
			{
				down[i] = 1;
			}
			if (hole[i].z >= h - r)
			{
				up[i] = 1;
			}
			for (int j = 1; j < i; j++)
			{
				int gi = dfn(i), gj = dfn(j);
				if (gi != gj)
				{
					long long d = pow(hole[i].x - hole[j].x, 2) + pow(hole[i].y - hole[j].y, 2) + pow(hole[i].z - hole[j].z, 2);
					if (d <= r * r * 4)
					{
						up[gj] = max(up[gi], up[gj]);
						down[gj] = max(down[gi], down[gj]);
						g[gi] = gj;
					}
				}
			}
		}
		int trig = 0;
		for (int i = 1; i <= n; i++)
		{
			if (up[i] == 1 && down[i] == 1)
			{
				trig = 1;
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