#include <algorithm>
#include <iostream>
using namespace std;
int x[15], vis[15], sel[15], s, pos;
int main()
{
	cin >> s;
	for (int i = 1; i <= 8; i++)
	{
		cin >> x[i];
		vis[x[i]] = 1;
	}
	for (int i = 1; i <= 12; i++)
	{
		if (vis[i] == 0)
		{
			sel[++pos] = i;
		}
	}
	for (int a = 1; a <= 4; a++)
	{
		for (int b = 1; b <= 4; b++)
		{
			if (a == b)
			{
				continue;
			}
			for (int c = 1; c <= 4; c++)
			{
				if (a == c || b == c)
				{
					continue;
				}
				int d = 10 - a - b - c;
				if (x[1] + x[3] + x[5] + sel[a] + sel[c] == s &&
					x[6] + x[7] + x[8] + sel[c] + sel[d] == s &&
					x[1] + x[2] + x[4] + x[8] + sel[b] == s)
				{
					cout << sel[a] << " " << sel[b] << " " << sel[c] << " " << sel[d] << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}