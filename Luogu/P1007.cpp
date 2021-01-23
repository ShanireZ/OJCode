#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int l, n;
	cin >> l >> n;
	int mint = 0, maxt = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos;
		cin >> pos;
		int t1 = l + 1 - pos, t2 = pos;
		if (t1 < t2)
		{
			swap(t1, t2);
		}
		maxt = max(maxt, t1), mint = max(mint, t2);
	}
	cout << mint << " " << maxt;
	return 0;
}