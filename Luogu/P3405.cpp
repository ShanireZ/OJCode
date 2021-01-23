#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
int main()
{
	int n, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string c, p, all, rall;
		cin >> c >> p;
		c = c.substr(0, 2);
		if (p == c)
		{
			continue;
		}
		all.append(c).append(p);
		rall.append(p).append(c);
		m[all]++;
		tot += m[rall];
	}
	cout << tot;
	return 0;
}