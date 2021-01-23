#include<iostream>
using namespace std;
int main()
{
	int n, t;
	cin >> n;
	do
	{
		t = 0;
		while(n)
		{
			t += n % 10;
			n /= 10;
		}
		n = t;
	}while(t / 10 != 0);
	cout << t;	
	return 0;
}
