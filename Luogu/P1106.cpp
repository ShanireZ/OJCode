#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int k;
	cin >> s >> k;
	int i = 0;
	while (i < s.size() - 1 && k > 0)
	{
		if (s[i] <= s[i + 1])
		{
			i++;
		}
		else
		{
			s.erase(i, 1);
			k--;
			i = 0;
		}
	}
	if (k)
	{
		s.erase(s.size() - k);
	}
	while (s[0] == '0')
	{
		s.erase(0, 1);
	}
	if (s.size() == 0)
	{
		s = "0";
	}
	cout << s;
	return 0;
}