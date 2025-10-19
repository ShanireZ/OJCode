#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, op;
	cin >> a >> b >> c >> op;
	if (op == 2)
	{
		cout << "Fail to pay." << endl;
	}
	else
	{
		cout << a + b + c << endl;
	}
	return 0;
}