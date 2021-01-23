#include <iostream>
#include <string>
using namespace std;
string f[3], f1[3];
int main()
{
	int n;
	cin >> n;
	cin >> f[0] >> f[1] >> f[2];
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			f1[j] += f[j][i];
		}
	}
	for (int a = 0; a < 3; a++)
	{
		int b = a + 1;
		int c = a + 2;
		if (b > 2)
		{
			b -= 3;
		}
		if (c > 2)
		{
			c -= 3;
		}
		for (int m = 1; m <= 2; m++)
		{
			for (int k = 0; k <= 6; k++)
			{
				string tmp1, tmp2;
				for (int i = 0; i < n; i++)
				{
					char tmp = f[b][i] - k;
					if (tmp < 'a')
					{
						tmp += 26;
					}
					tmp1 += tmp;
					tmp = f[c][i] + k - 26;
					if (tmp < 'a')
					{
						tmp += 26;
					}
					tmp2 += tmp;
				}
				if (f1[a] == tmp1 && f1[a] == tmp2)
				{
					cout << f1[a];
					return 0;
				}
			}
			swap(b, c);
		}
	}
	return 0;
}