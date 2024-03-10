#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int check(double t, int k)
{
	if (t >= 37.5 && k == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string name;
		double tw;
		int ks;
		cin >> name >> tw >> ks;
		if (check(tw, ks) == 1)
		{
			cnt++;
			cout << name << endl;
		}
	}
	cout << cnt << endl;
	return 0;
}