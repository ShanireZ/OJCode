#include <iostream>
using namespace std;
int main()
{
	long long n, m, r, c, x1, y1, x2, y2, ans = 0;
	cin >> n >> m >> r >> c >> x1 >> y1 >> x2 >> y2;
	ans = (x2 / r - x1 / r + 1) * (y2 / c - y1 / c + 1);
	cout << ans << endl;
	return 0;
}