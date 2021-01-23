#include<iostream>
using namespace std;
int main()
{
	int n, sum = 182, i;
	for(i = 0; i < 25; i++)
	{
		cin >>n;
		sum -= n;
	}
	cout << sum;
	return 0;
}
