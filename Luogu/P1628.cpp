#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct cmp
{
	bool operator()(string a, string b)
	{
		return a > b;
	}
};
priority_queue<string, vector<string>, cmp> q;
string a[100005];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	string t;
	cin >> t;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].find(t) == 0)
		{
			q.push(a[i]);
		}
	}
	while (q.size())
	{
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}