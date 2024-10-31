#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int r[100005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	sort(r + 1, r + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (q.size() && q.front() < r[i])
		{
			q.pop();
		}
		q.emplace(r[i]);
	}
	cout << q.size() << endl;
	return 0;
}