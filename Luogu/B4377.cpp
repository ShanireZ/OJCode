#include <algorithm>
#include <iostream>
using namespace std;
string s;
int c1, c2;
int main()
{
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == 'A')
		{
			i % 2 == 0 ? c1++ : c2++;
		}
	}
	if ((c1 + c2) % 2 == 1)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << abs(c1 - c2) / 2 << endl;
	}
	return 0;
}