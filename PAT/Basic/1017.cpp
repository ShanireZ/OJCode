#include <iostream>
#include <string>
using namespace std;
string s, num;
int main()
{
	int x, now = 0;
	cin >> num >> x;
	for (int i = 0; i < (int)num.size(); i++)
	{
		now = now * 10 + num[i] - '0';
		s += '0' + now / x;
		now = now % x;
	}
	int pos = 0;
	while (s[pos] == '0' && pos < (int)s.size())
	{
		pos++;
	}
	if (pos == (int)s.size())
	{
		pos--;
	}
	cout << s.substr(pos) << " " << now << "\n";
	return 0;
}