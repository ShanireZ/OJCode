#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s[3005];
struct Node
{
	string s;
	int id;
	bool operator<(const Node &oth) const
	{
		return s < oth.s;
	}
};
Node ns[3005];
int main()
{
	int n, m;
	cin >> n >> m;
	if(n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		ns[i] = Node{s[i], i};
		sort(s[i].begin(), s[i].end());
		sort(ns[i].s.begin(), ns[i].s.end(), greater<char>());
	}
	sort(ns + 1, ns + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		if ((i != ns[1].id && s[i] >= ns[1].s) ||
			(i == ns[1].id && s[i] >= ns[2].s))
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
	}
	cout << endl;
	return 0;
}