#include <iostream>
#include <vector>
using namespace std;
int p[15];
int main()
{
	int n, r;
	cin >> n >> r;
	int h = r % 10, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = h; j >= 1; j--)
		{
			if (p[j] != 0)
			{
				ans += i - p[j] - 1;
			}
			p[j] = i;
		}
		r = (r * 6807 + 2831) % 201701;
		h = r % 10;
	}
	cout << ans << "\n";
	return 0;
}