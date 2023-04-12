#include <iostream>
#include <string>
using namespace std;
int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x = abs(x1 - x2), y = abs(y1 - y2), ans = -1;
	if (x % 2 == y % 2)
	{
		ans = x + y;
		if ((x2 >= x1 && y2 >= y1) || (x2 <= x1 && y2 <= y1))
		{
			ans -= x % 2;
		}
		else
		{
			ans += x % 2;
		}
	}
	cout << ans << "\n";
	return 0;
}