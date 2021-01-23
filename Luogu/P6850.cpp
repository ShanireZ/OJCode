#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, e, f, g, h, i;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
	int tot = 50 + a + b + c + d + e + f + g + h * 5;
	if (tot >= i)
	{
		cout << "AKIOI";
	}
	else
	{
		cout << "AFO";
	}
	return 0;
}