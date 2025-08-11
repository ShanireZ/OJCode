#include <algorithm>
#include <iostream>
using namespace std;
int n, x, y;
int main()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n && x < y; i++)
	{
		int a, b;
		cin >> a >> b;
		if (x < a)
		{
			break;
		}
		x = x - a + b;
	}
	cout << x << endl;
	return 0;
}