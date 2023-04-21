#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
	long long tot;
	int id;
	bool operator<(const Node oth) const
	{
		return (tot == oth.tot) ? (id > oth.id) : (tot > oth.tot);
	}
};
priority_queue<Node> q;
vector<int> ans[5005];
int read();
int main()
{
	ios::sync_with_stdio(false);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		q.push(Node{0, i});
	}
	for (int i = 1; i <= m; i++)
	{
		Node now = q.top();
		q.pop();
		now.tot += read();
		q.push(now), ans[now.id].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if ((int)ans[i].size() == 0)
		{
			printf("0\n");
			continue;
		}
		for (int j = 0; j < (int)ans[i].size(); j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}