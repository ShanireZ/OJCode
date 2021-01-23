#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int minn[50005][20];
int maxn[50005][20];
int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> minn[i][0];
		maxn[i][0] = minn[i][0];
	}
	for (int i = 1; i <= log2(n); i++)
	{
		for (int j = 1; j + pow(2, i) - 1 <= n; j++)
		{
			int half = j + pow(2, i - 1);
			minn[j][i] = min(minn[j][i - 1], minn[half][i - 1]);
			maxn[j][i] = max(maxn[j][i - 1], maxn[half][i - 1]);
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
		int t = log2(r - l + 1);
		int half = r - pow(2, t) + 1;
		int low = min(minn[l][t], minn[half][t]);
		int high = max(maxn[l][t], maxn[half][t]);
		cout << high - low << endl;
	}
	return 0;
}