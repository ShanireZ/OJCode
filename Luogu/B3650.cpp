#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += i;
		cout << tot << '\n';
	}
	return 0;
}