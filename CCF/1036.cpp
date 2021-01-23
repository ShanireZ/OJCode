#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b;
	cin >> n;
	while(n != 0)
	{
		a = n / 2;
		b = n % 2;
		n /= 2;
		cout << "shang:" << a << " " << "yu:" << b << endl; 
	}
}
