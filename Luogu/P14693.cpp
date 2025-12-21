#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		long long res = c * a * 2;
		b = b - c;
		if (b > 140)
		{
			res += (b - 140) * 1.5 * a + 140 * a;
		}
		else
		{
			res += b * a;
		}
		long long bt[20] = {0}, pos = 0;
		while (res)
		{
			bt[++pos] = res % 10;
			res /= 10;
		}
		if (pos == 0)
		{
			cout << "0" << endl;
			continue;
		}
		for (int i = pos; i >= 1; i--)
		{
			cout << bt[i];
			if (i % 3 == 1 && i > 1)
			{
				cout << ",";
			}
		}
		cout << endl;
	}
	return 0;
}