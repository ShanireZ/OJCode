#include <iostream>
using namespace std;
int main()
{
	cout << "[1] apples" << endl << "[2] pears" << endl << "[3] oranges" << endl << "[4] grapes" << endl << "[0] Exit" << endl;
	int a;
	cin >> a;
	switch(a)
	{
		case 1:
			cout << "price=3";
			break;
		case 2:
			cout << "price=2.5";
			break;
		case 3:
			cout << "price=4.1";
			break;
		case 4:
			cout << "price=10.2";
			break;
		case 0:
			break;
		default:
			cout << "price=0";
	}
	return 0;
}
