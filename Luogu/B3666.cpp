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
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		unsigned long long x;
		cin >> x;
		ans ^= i;
		while (q.size() && q.back().v <= x)
		{
			ans ^= q.back().id;
			q.pop_back();
		}
		q.push_back(Node{i, x});
		cout << ans << '\n';
	}
	return 0;
}