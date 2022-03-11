#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
struct Person
{
	int t, id;
};
bool cmp(Person x, Person y)
{
	return x.t < y.t;
}
Person p[1005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].t;
		p[i].id = i;
	}
	sort(p + 1, p + 1 + n, cmp);
	double tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += (n - i) * p[i].t;
		cout << p[i].id << " ";
	}
	cout << endl;
	cout << fixed << setprecision(2) << tot / n << endl;
	return 0;
}