#include <iostream>
using namespace std;
int days[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
	int st, ed, xq = 1, ans = 0;
	cin >> st >> ed;
	for (int y = 1900; y <= ed; y++)
	{
		int ex = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
		for (int m = 1; m <= 12; m++)
		{
			for (int d = 1; d <= days[m] + (m == 2 && ex); d++)
			{
				if (y >= st && m == 11 && d == 11 && (xq == 6 || xq == 7))
				{
					ans++;
				}
				xq = (xq == 7 ? 1 : xq + 1);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}