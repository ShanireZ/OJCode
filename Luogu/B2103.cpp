#include <iomanip>
#include <iostream>
using namespace std;
int a[105][105];
int main()
{
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			if (x == a[i][j])
			{
				cnt++;
			}
		}
	}
	cout << fixed << setprecision(2) << 100.0 * cnt / (n * m) << endl;
	return 0;
}