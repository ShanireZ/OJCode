#include <iostream>
#include <deque>
using namespace std;
deque<int> q;
int cnt[2005];
int id[1000005];
int main()
{
	int n, m, tot = 0, minl = 0x3f3f3f3f, l, r;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> id[i];
		if (cnt[id[i]] == 0)
		{
			tot++;
		}
		cnt[id[i]]++;
		q.push_back(i);
		while (q.size() && cnt[id[q.front()]] > 1) //多了的从前端pop掉 只留一个
		{
			cnt[id[q.front()]]--;
			q.pop_front();
		}
		if (tot == m && minl > q.size())
		{
			minl = q.size();
			l = q.front();
			r = q.back();
		}
	}
	cout << l << " " << r;
	return 0;
}