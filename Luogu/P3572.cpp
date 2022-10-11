#include <deque>
#include <iostream>
using namespace std;
#define MX 1000005
int h[MX], cost[MX];
deque<int> dq;
int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int k;
		cin >> k;
		dq.clear();
		dq.push_back(1);
		for (int j = 2; j <= n; j++)
		{
			int pos = dq.front();
			while (pos + k < j)
			{
				dq.pop_front();
				pos = dq.front();
			}
			cost[j] = cost[pos] + (h[pos] <= h[j]);
			pos = dq.back();
			while (cost[pos] > cost[j] || (cost[pos] == cost[j] && h[pos] <= h[j]))
			{
				dq.pop_back();
				pos = dq.back();
			}
			dq.push_back(j);
		}
		cout << cost[n] << endl;
	}
	return 0;
}