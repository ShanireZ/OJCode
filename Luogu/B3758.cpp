#include <iostream>
#include <string>
using namespace std;
int add[1005], cnt, pos, r = 1;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == ')' && cnt)
		{
			cnt--;
		}
		else if (s[i] == '(')
		{
			cnt++;
		}
		else
		{
			add[++pos] = i;
		}
	}
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (r <= pos && i == add[r])
		{
			cout << '(';
			r++;
		}
		cout << s[i];
	}
	while (cnt--)
	{
		cout << ')';
	}
	return 0;
}