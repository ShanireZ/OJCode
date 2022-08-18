#include <iostream>
using namespace std;
int main()
{
	char ch;
	cin >> ch;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3 - i; j++)
		{
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; j++)
		{
			cout << ch;
		}
		cout << endl;
	}
	return 0;
}