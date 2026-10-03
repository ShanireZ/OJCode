#include <algorithm>
#include <iostream>
using namespace std;
string s, d;
int main()
{
	cin >> s >> d;
	int a = 0, b = 0;
	while (a < (int)s.size() && b < (int)d.size())
	{
		if (s[a] == d[b])
		{
			a++;
		}
		b++;
	}
	if (a == (int)s.size())
	{
		cout << b << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}