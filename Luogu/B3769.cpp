#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int q;
	string s, t;
	cin >> s >> t >> q;
	while (q--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		string s1 = s.substr(l1 - 1, r1 - l1 + 1), s2 = t.substr(l2 - 1, r2 - l2 + 1);
		if (s1 == s2)
		{
			cout << "ovo\n";
		}
		else if (s1 < s2)
		{
			cout << "yifusuyi\n";
		}
		else
		{
			cout << "erfusuer\n";
		}
	}
	return 0;
}