#include <iostream>
#include <map>
using namespace std;
map<int, map<int, int>> m;
int main()
{
	int n, q;
	cin >> n >> q;
	for (int r = 1; r <= q; r++)
	{
		int t, i, j, k;
		cin >> t >> i >> j;
		if (t == 1)
		{
			cin >> k;
			m[i][j] = k;
		}
		else
		{
			cout << m[i][j] << endl;
		}
	}
	return 0;
}