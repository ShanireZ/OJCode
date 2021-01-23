#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int h[1000005];
long long v[1000005];
long long rec[1000005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i] >> v[i];
		while (s.size() && h[s.top()] < h[i]) //向右传播传给谁
		{
			rec[i] += v[s.top()];
			s.pop();
		}
		if (s.size()) //向左传播传给谁
		{
			rec[s.top()] += v[i];
		}
		s.push(i);
	}
	long long maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		maxv = max(maxv, rec[i]);
	}
	cout << maxv;
	return 0;
}