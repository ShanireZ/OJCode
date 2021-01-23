#include <iostream>
#include <cmath>
using namespace std;
int s[1005][4];
int main()
{
	int n, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1] >> s[i][2];
		s[i][3] = s[i][0] + s[i][1] + s[i][2];
		for (int j = 1; j < i; j++)
		{
			if (abs(s[i][0] - s[j][0]) <= 5 && abs(s[i][1] - s[j][1]) <= 5 && abs(s[i][2] - s[j][2]) <= 5)
			{
				if (abs(s[i][3] - s[j][3]) <= 10)
				{
					tot++;
				}
			}
		}
	}
	cout << tot;
	return 0;
}