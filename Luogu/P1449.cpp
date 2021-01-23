#include <iostream>
#include <stack>
using namespace std;
stack<int> stk;
int main()
{
	int num = 0;
	char tmp;
	cin >> tmp;
	while (tmp != '@')
	{
		if (tmp >= '0' && tmp <= '9')
		{
			num = num * 10 + tmp - '0';
		}
		else if (tmp == '.')
		{
			stk.push(num);
			num = 0;
		}
		else
		{
			int n1 = stk.top();
			stk.pop();
			int n2 = stk.top();
			stk.pop();
			if (tmp == '+')
			{
				stk.push(n2 + n1);
			}
			else if (tmp == '-')
			{
				stk.push(n2 - n1);
			}
			else if (tmp == '*')
			{
				stk.push(n2 * n1);
			}
			else if (tmp == '/')
			{
				stk.push(n2 / n1);
			}
		}
		cin >> tmp;
	}
	cout << stk.top();
	return 0;
}