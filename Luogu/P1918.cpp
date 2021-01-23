#include <iostream>
#include <map>
using namespace std;
map<int, int> mp;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		mp[a] = i;
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int m;
		cin >> m;
		cout << mp[m] << endl;
	}
	return 0;
}