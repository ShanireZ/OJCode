#include <iostream>
#include <deque>
using namespace std;
deque<int> q;
deque<int> k;
int score[100005];
int sums[100005]; //前缀和
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
		sums[i] = sums[i - 1] + score[i];
		while (q.size() && score[q.back()] >= score[i])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	double maxavg = 0;
	for (int i = 1; i <= n - 2; i++)
	{
		while (q.front() <= i)
		{
			q.pop_front();
		}
		double avg = 1.0 * (sums[n] - sums[i] - score[q.front()]) / (n - i - 1);
		if (avg > maxavg)
		{
			maxavg = avg;
			k.clear();
			k.push_back(i);
		}
		else if (avg == maxavg)
		{
			k.push_back(i);
		}
	}
	while (k.size())
	{
		cout << k.front() << endl;
		k.pop_front();
	}
	return 0;
}