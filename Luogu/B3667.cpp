#include <deque>
#include <iostream>
using namespace std;
struct Node
{
	int id;
	unsigned long long v;
};
deque<Node> q;
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		unsigned long long x;
		cin >> x;
		while (q.size() && q.front().id + k - 1 < i)
		{
			q.pop_front();
		}
		while (q.size() && q.back().v <= x)
		{
			q.pop_back();
		}
		q.push_back(Node{i, x});
		if (i >= k)
		{
			cout << q.size() << '\n';
		}
	}
	return 0;
}