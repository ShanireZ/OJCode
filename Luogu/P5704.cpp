#include <iostream>
using namespace std;
int main()
{
	char ch;
	cin >> ch;
	ch -= 'a' - 'A';
	cout << ch;
	return 0;
}