#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << (1ll + i) * i / 2 << '\n';
	}
	return 0;
}