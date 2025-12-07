#include <algorithm>
#include <iostream>
using namespace std;
int ans, n, r[400][400], p[100005][2];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		p[i][0] = b, p[i][1] = c;
		r[b][c] = (r[b][c] == 0 ? a : min(r[b][c], a));
	}
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, r[p[i][0]][p[i][1]]);
	}
	cout << ans << endl;
	return 0;
}