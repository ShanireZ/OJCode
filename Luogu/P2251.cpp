#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int minn[1000005][20];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> minn[i][0];
	}
	for (int i = 1; i <= log2(n); i++)
	{
		for (int j = 1; j + pow(2, i) - 1 <= n; j++)
		{
			int half = j + pow(2, i - 1);
			minn[j][i] = min(minn[j][i - 1], minn[half][i - 1]);
		}
	}
	for (int i = 1; i <= n - m + 1; i++)
	{
		int l = i, r = l + m - 1;
		int t = log2(m);
		int half = r - pow(2, t) + 1;
		cout << min(minn[l][t], minn[half][t]) << endl;
	}
	return 0;
}