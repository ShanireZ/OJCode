#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
	int n, q, rev = 0, inv = 0;
	cin >> n >> q >> s;
	while (q--)
	{
		char c;
		cin >> c;
		c == '1' ? rev ^= 1 : inv ^= 1;
	}
	if (rev)
	{
		reverse(s.begin(), s.end());
	}
	for (char c : s)
	{
		int x = c - '0';
		cout << (inv ? (x ^ 1) : x);
	}
	return 0;
}