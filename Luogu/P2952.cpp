#include <iostream>
#include <deque>
using namespace std;
deque<int> q;
int main()
{
	int n, cur = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char type, side;
		cin >> type >> side;
		if (type == 'A')
		{
			if (side == 'L')
			{
				q.push_front(cur++);
			}
			else
			{
				q.push_back(cur++);
			}
		}
		else
		{
			int k;
			cin >> k;
			if (side == 'L')
			{
				for (int j = 1; j <= k; j++)
				{
					q.pop_front();
				}
			}
			else
			{
				for (int j = 1; j <= k; j++)
				{
					q.pop_back();
				}
			}
		}
	}
	while (q.size())
	{
		cout << q.front() << endl;
		q.pop_front();
	}
	return 0;
}