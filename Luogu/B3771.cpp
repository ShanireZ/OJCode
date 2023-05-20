#include <iostream>
using namespace std;
int main()
{
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		int ok = 1, x = i / 10, pre = i % 10;
		while (x)
		{
			if (x % 10 >= pre)
			{
				ok = 0;
				break;
			}
			pre = x % 10, x /= 10;
		}
		cnt += ok;
	}
	cout << cnt << "\n";
	return 0;
}