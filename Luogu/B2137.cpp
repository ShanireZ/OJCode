#include <algorithm>
#include <iostream>
using namespace std;
int prim[1100005];
int main()
{
	int x, y, cnt = 0;
	cin >> x >> y;
	if (x > y)
	{
		swap(x, y);
	}
	prim[0] = 1, prim[1] = 1;
	for (int i = 2; i <= y; i++)
	{
		if (prim[i] == 0)
		{
			if (x <= i)
			{
				cnt++;
			}
			for (int j = i * 2; j <= y; j += i)
			{
				prim[j] = 1;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}