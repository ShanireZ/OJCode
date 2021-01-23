#include <iostream>
#include <string>
using namespace std;
int main()
{
	string isbn;
	cin >> isbn;
	int check = 0, p = 1;
	for (int i = 0; i <= 10; i++)
	{
		if (isbn[i] >= '0' && isbn[i] <= '9')
		{
			check += (isbn[i] - '0') * p++;
		}
	}
	check %= 11;
	if (check < 10 && check + '0' == isbn[12] || check == 10 && isbn[12] == 'X')
	{
		cout << "Right";
	}
	else
	{
		isbn.erase(12);
		cout << isbn;
		if (check < 10)
		{
			cout << check;
		}
		else
		{
			cout << 'X';
		}
	}
	return 0;
}