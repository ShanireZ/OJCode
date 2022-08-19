#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<int> a, b, c, all;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a.insert(x);
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		b.insert(x);
	}
	for (int i = 0; i < 64; i++)
	{
		all.insert(i);
	}
	cout << a.size() << endl; // 1
	c.clear();
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
	for (auto x : c)
	{
		cout << x << " ";
	}
	cout << endl; // 2
	c.clear();
	set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
	for (auto x : c)
	{
		cout << x << " ";
	}
	cout << endl; // 3
	c.clear();
	set_symmetric_difference(a.begin(), a.end(), all.begin(), all.end(), inserter(c, c.begin()));
	for (auto x : c)
	{
		cout << x << " ";
	}
	cout << endl; // 4
	c.clear();
	set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
	if (c.size() == 0)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	} // 5
	c.clear();
	set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
	if (c.size() == 0)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	} // 6
	if (a.size() && *a.begin() == 0)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	} // 7
	return 0;
}