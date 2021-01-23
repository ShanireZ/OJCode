#include <iostream>
using namespace std;
int m[105][105][2]; //0表示竖直 1表示水平
int main()
{
	int r, c, k, tot = 0;
	cin >> r >> c >> k;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '.')
			{
				m[i][j][0] = m[i - 1][j][0] + 1;
				m[i][j][1] = m[i][j - 1][1] + 1;
				tot += (m[i][j][0] >= k) ? 1 : 0;
				tot += (m[i][j][1] >= k) ? 1 : 0;
			}
		}
	}
	tot /= (k == 1) ? 2 : 1;
	cout << tot;
	return 0;
}