#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int n, ex, p1, p2 = 1;
int main()
{
	cin >> n;
	while (cin >> t)
	{
		s += t;
	}
	s += s;
	while (ex < n && p1 < n && p2 < n)
	{
		if (s[p1 + ex] == s[p2 + ex])
		{
			ex++;
		}
		else
		{
			s[p1 + ex] > s[p2 + ex] ? p1 = p1 + ex + 1 : p2 = p2 + ex + 1;
			ex = 0;
			if (p1 == p2)
			{
				p2++;
			}
		}
	}
	cout << min(p1, p2) << endl;
	return 0;
}