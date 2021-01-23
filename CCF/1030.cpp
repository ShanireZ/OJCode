#include <iostream>
using namespace std;
int main()
{
	unsigned long long n, t = 1;
	cin >> n;
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			n /= 2;
		}else
		{
			n = 3 * n + 1;
		}
		t++;
	}
	cout << t;
	return 0;
}
