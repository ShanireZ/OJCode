#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	long long a, b, d;
	cin >> a >> b >> d;
	a = a + b;
	if (a == 0)
	{
		cout << 0;
		return 0;
	}
	string s;
	while (a)
	{
		s += a % d + '0';
		a /= d;
	}
	reverse(s.begin(), s.end());
	cout << s;
	return 0;
}