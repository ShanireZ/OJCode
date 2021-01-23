#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
priority_queue<int, vector<int>, cmp> q;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (op == 2)
		{
			cout << q.top() << endl;
		}
		else
		{
			q.pop();
		}
	}
	return 0;
}