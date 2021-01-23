#include<iostream>
using namespace std;
int main()
{
	int n = 0, t5, sum, o;
	cin >> o;
	o /= 10;
	for(t5 = 0; t5 <= o/5; t5++)
	{
		sum = o - t5 * 5;
		n += sum / 2 + 1;
	}
	cout << n;
	return 0;
}
