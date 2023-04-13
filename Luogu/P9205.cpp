#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	long long n, xe, ye, x, y;
	cin >> n >> xe >> ye >> x >> y;
	long long ans = abs(x - xe) + abs(y - ye);
	for (int i = 2; i <= n; i++)
	{
		cin >> x >> y;
		if (xe > x + i - 1) // 如果出现在最后一列也不行
		{
			ans += xe - (x + i - 1);
		}
		else if (xe < x)
		{
			ans += x - xe;
		}
		if (ye < y - i + 1) // 如果出现在最后一行也不行
		{
			ans += (y - i + 1) - ye;
		}
		else if (ye > y)
		{
			ans += ye - y;
		}
	}
	cout << ans << endl;
	return 0;
}