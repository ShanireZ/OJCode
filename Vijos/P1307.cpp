#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += i * i;
	}
	cout << tot;
	return 0;
}