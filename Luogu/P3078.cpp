#include <iostream>
using namespace std;
long long a[100005];
int main()
{
	int n;
	long long tot = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > a[i - 1])
		{
			tot += a[i] - a[i - 1];
		}
	}
	cout << tot;
	return 0;
}