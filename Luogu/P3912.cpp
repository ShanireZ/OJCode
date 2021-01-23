#include <iostream>
#include <cmath>
using namespace std;
bool judge[100000001];
int main()
{
	register int n, count;
	cin >> n;
	count = n - 1;
	for (register int i = 2; i <= sqrt(n); i++)//根号n之后的合数都可通过前面的素数倍数筛除
	{
		if (judge[i] == 0)
		{
			for (register int j = 2; i * j <= n; j++)//筛除合数
			{
				if (judge[j * i] == 0)
				{
					judge[j * i] = 1;
					count--;
				}
			}
		}
	}
	cout << count;
	return 0;
}