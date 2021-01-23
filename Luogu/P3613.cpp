#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> g;
int main()
{
	int n, q;
	cin >> n >> q;
	for (int r = 1; r <= q; r++)
	{
		int t, k;
		string i, j, str;
		cin >> t >> i >> j;
		str.append(i).append("-").append(j);
		if (t == 1)
		{
			cin >> k;
			g[str] = k;
		}
		else
		{
			cout << g[str] << endl;
		}
	}
	return 0;
}