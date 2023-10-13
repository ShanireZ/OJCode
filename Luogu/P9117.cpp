#include <iostream>
using namespace std;
struct Node
{
	int c, t;
};
Node h[100005], l[100005];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, q;
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++)
		{
			h[i] = Node{0, 0};
		}
		for (int i = 1; i <= m; i++)
		{
			l[i] = Node{0, 0};
		}
		for (int i = 1; i <= q; i++)
		{
			int opt, x, c;
			cin >> opt >> x >> c;
			if (opt == 0)
			{
				h[x] = Node{c, i};
			}
			else
			{
				l[x] = Node{c, i};
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (h[i].t > l[j].t)
				{
					cout << h[i].c << " ";
				}
				else
				{
					cout << l[j].c << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}