#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 數字前後及運算符前後都會有空格,且a b不一定為兩位數字
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