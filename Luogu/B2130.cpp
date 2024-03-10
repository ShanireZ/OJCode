#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 数字前后及运算符前后都会有空格,且a b不一定为两位数字
int main()
{
	int a, b;
	char c;
	cin >> a >> c >> b;
	if (c == '+')
	{
		cout << a + b << endl;
	}
	else if (c == '-')
	{
		cout << a - b << endl;
	}
	else if (c == '*')
	{
		cout << a * b << endl;
	}
	else if (c == '/')
	{
		cout << a / b << endl;
	}
	else if (c == '%')
	{
		cout << a % b << endl;
	}
	return 0;
}