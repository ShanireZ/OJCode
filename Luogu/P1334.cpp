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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}
	long long ans = 0;				 //合并果子反向版本
	for (int i = n - 1; i >= 1; i--) //第n-1次~第1次
	{
		int tot = q.top();
		q.pop();
		tot += q.top();
		q.pop();
		ans += tot;
		q.push(tot);
	}
	cout << ans;
	return 0;
}