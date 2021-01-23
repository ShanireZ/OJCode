#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;
int v[1000005];
int n, k;
deque<int> q;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
inline void make(int t)
{
	q.clear();
	for (int i = 1; i <= n; i++)
	{
		if (t == 0)
		{
			while (q.size() && v[q.back()] >= v[i])
			{
				q.pop_back();
			}
		}
		else if (t == 1)
		{
			while (q.size() && v[q.back()] <= v[i])
			{
				q.pop_back();
			}
		}
		q.push_back(i);
		while (q.front() < i - k + 1)
		{
			q.pop_front();
		}
		if (i >= k)
		{
			printf("%d ", v[q.front()]);
		}
	}
	printf("\n");
}
int main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++)
	{
		v[i] = read();
	}
	make(0);
	make(1);
	return 0;
}