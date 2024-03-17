#include <algorithm>
#include <iostream>
using namespace std;
int prim[50005];
int main()
{
	int n, cnt = 0;
	cin >> n;
	prim[0] = 1, prim[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (prim[i] == 0)
		{
			cnt++;
			for (int j = i * 2; j <= n; j += i)
			{
				prim[j] = 1;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}