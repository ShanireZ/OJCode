#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int p;
		cin >> p;
		if (p <= 10)
		{
			cout << "R" << endl;
		}
		else if (p <= 20)
		{
			cout << "L" << endl;
		}
		else
		{
			cout << p << endl;
		}
	}
	return 0;
}