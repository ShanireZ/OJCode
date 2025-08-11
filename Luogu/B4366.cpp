#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n, k;
queue<int> a, b;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		i <= k ? a.push(x) : b.push(x);
	}
	while (a.size() && b.size())
	{
		cout << a.front() << " " << b.front() << " ";
		a.pop(), b.pop();
	}
	while (a.size())
	{
		cout << a.front() << " ";
		a.pop();
	}
	while (b.size())
	{
		cout << b.front() << " ";
		b.pop();
	}
	return 0;
}