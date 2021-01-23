#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str;
	cin >> str;
	char mark = ' ';
	int pos = str.size();
	for (int i = 0; i < str.size(); i++) //查找是否有符号 如果没有pos仍为str.size()
	{
		if (str[i] > '9' || str[i] < '0')
		{
			pos = i;
			mark = str[i];
			break;
		}
	}
	string a, b; //a前半部分 b后半部分
	a = str.substr(0, pos);
	if (mark == '.' || mark == '/')
	{
		b = str.substr(pos + 1);
	}
	reverse(a.begin(), a.end()); //反转
	reverse(b.begin(), b.end());
	while (a.size() > 1 && a[0] == '0') //a去前0
	{
		a.erase(0, 1);
	}
	if (mark == '/') //b去前0
	{
		while (b.size() > 1 && b[0] == '0')
		{
			b.erase(0, 1);
		}
	}
	else if (mark == '.') //b去后0
	{
		while (b.size() > 1 && b[b.size() - 1] == '0')
		{
			b.erase(b.size() - 1, 1);
		}
	}
	cout << a << mark << b;
	return 0;
}