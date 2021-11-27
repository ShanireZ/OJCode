#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch > '9' || ch < '0')
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
priority_queue<int, vector<int>, greater<int>> up;
priority_queue<int, vector<int>, less<int>> down;
int main()
{
	int n = read(), k = 1;
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		down.push(x);
		if (down.size() == k)
		{
			up.push(down.top());
			down.pop();
		}
		if (k * 2 - 1 == i)
		{
			printf("%d\n", up.top());
			down.push(up.top());
			up.pop();
			k++;
		}
	}
	return 0;
}