#include <iostream>
#include <string>
using namespace std;
int usd[105];
int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ']' || str[i] == ')')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (usd[j] == 0 && (str[j] == '(' || str[j] == '['))
				{
					if (str[i] - str[j] == 2 || str[i] - str[j] == 1)
					{
						usd[i] = usd[j] = 1;
					}
					break;
				}
			}
		}
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (usd[i] == 1)
		{
			cout << str[i];
		}
		else if (str[i] == '[' || str[i] == ']')
		{
			cout << "[]";
		}
		else if (str[i] == '(' || str[i] == ')')
		{
			cout << "()";
		}
	}
	return 0;
}