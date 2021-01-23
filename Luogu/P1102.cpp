#include <iostream>
#include <map>
using namespace std;
int a[200005];
map<int, int> mp;
int main()
{
	int n, c;
	long long tot = 0;
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		a[i] = num;
		mp[num]++;
	}
	for(int i = 1; i <= n; i++)
	{
		int num = a[i] - c;
		tot += mp[num];
	}
	cout << tot;
	return 0;
}