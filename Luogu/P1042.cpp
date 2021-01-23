#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string str[2505];
int p;
void score(int point)
{
	int a = 0, b = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < str[i].size(); j++)
		{
			if (str[i][j] == 'E')
			{
				cout << a << ":" << b << endl;
				return;
			}
			else if (str[i][j] == 'W')
			{
				a++;
			}
			else
			{
				b++;
			}
			if ((a >= point || b >= point) && abs(a - b) >= 2)
			{
				cout << a << ":" << b << endl;
				a = 0;
				b = 0;
			}
		}
	}
}
int main()
{
	while (cin >> str[p])
	{
		p++;
	}
	score(11);
	cout << endl;
	score(21);
	return 0;
}