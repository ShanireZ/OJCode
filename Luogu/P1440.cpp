#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;
deque<int> q;
int v[2000005];
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
int main()
{
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		while (q.front() < i - m)
		{
			q.pop_front();
		}
		if (q.size() == 0)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", v[q.front()]);
		}
		v[i] = read();
		while (q.size() && v[q.back()] >= v[i])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	return 0;
}