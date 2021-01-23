#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
priority_queue<int> qk, qd, qm, qf;
int main()
{
	int k, d, m, f;
	cin >> k >> d >> m >> f;
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		qk.push(x);
	}
	for (int i = 1; i <= d; i++)
	{
		int x;
		cin >> x;
		qd.push(x);
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		qm.push(x);
	}
	for (int i = 1; i <= f; i++)
	{
		int x;
		cin >> x;
		qf.push(x);
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		double s = 0;
		s += qk.top();
		qk.pop();
		for (int j = 1; j <= a; j++)
		{
			s += qd.top();
			qd.pop();
		}
		for (int j = 1; j <= b; j++)
		{
			s += qm.top();
			qm.pop();
		}
		for (int j = 1; j <= c; j++)
		{
			s += qf.top();
			qf.pop();
		}
		cout << fixed << setprecision(2) << s / 11 << endl;
	}
	return 0;
}