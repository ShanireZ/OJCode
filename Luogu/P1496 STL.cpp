#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int, int> mp;
set<int> s;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		mp[a]++, mp[b]--;
		s.insert(a), s.insert(b);
	}
	int tot = 0, status = 0, pre;
	for (auto x : s)
	{
		if (status > 0)
		{
			tot += x - pre;
		}
		status += mp[x], pre = x;
	}
	cout << tot << endl;
	return 0;
}