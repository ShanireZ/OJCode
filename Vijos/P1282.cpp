#include <iostream>
#include <algorithm>
using namespace std;
struct Fan
{
	int id, power;
};
Fan fans[50005];
int e[11];
bool cmp(Fan a, Fan b)
{
	if (a.power == b.power)
	{
		return a.id < b.id;
	}
	return a.power > b.power;
}
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 10; i++)
	{
		cin >> e[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> fans[i].power;
		fans[i].id = i;
	}
	sort(fans + 1, fans + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		int tmp = (i - 1) % 10 + 1;
		fans[i].power += e[tmp];
	}
	sort(fans + 1, fans + 1 + n, cmp);
	for (int i = 1; i <= k; i++)
	{
		cout << fans[i].id << " ";
	}
	return 0;
}