#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string m[1005];
int s[1005];
int main()
{
	int num = 0;
	int pos = 0;
	while (true)
	{
		char ch;
		ch = getchar();
		if (ch >= '0' && ch <= '9')
		{
			num = num * 10 + ch - '0';
		}
		else if (ch == ' ')
		{
			s[pos++] = num;
			num = 0;
		}
		else
		{
			break;
		}
	}
	s[pos] = num;
	for (int i = 0; i <= pos; i++)
	{
		string str;
		cin >> str;
		m[s[i]] = str;
	}
	for (int i = 1; i <= pos + 1; i++)
	{
		cout << m[i] << endl;
	}
	return 0;
}