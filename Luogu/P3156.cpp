#include <iostream>
using namespace std;
int a[2000005];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		int id;
		cin >> id;
		cout << a[id] << endl;
	}
	return 0;
}