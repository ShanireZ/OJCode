#include <algorithm>
#include <iostream>
using namespace std;
int prim[10005], all[10005], pos;
int main()
{
	int n;
	cin >> n;
	prim[0] = 1, prim[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (prim[i] == 0)
		{
			pos++;
			all[pos] = i;
			for (int j = i * 2; j <= n; j += i)
			{
				prim[j] = 1;
			}
		}
	}
	for (int i = 2; i <= pos; i++)
	{
		if (all[i] - all[i - 1] == 2)
		{
			cout << all[i - 1] << " " << all[i] << endl;
		}
	}
	return 0;
}