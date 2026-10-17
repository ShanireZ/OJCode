#include <iostream>
#include <cmath>
using namespace std;
bool judge[100000001];
int main()
{
	register int n, count;
	cin >> n;
	count = n - 1;
	for (register int i = 2; i <= sqrt(n); i++)//根號n之後的合數都可通過前面的素數倍數篩除
	{
		if (judge[i] == 0)
		{
			for (register int j = 2; i * j <= n; j++)//篩除合數
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