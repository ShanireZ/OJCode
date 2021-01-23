#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
int v[3000005];
int f[3000005];
stack<int> s;
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
	int n = read();
	for (int i = 1; i <= n; i++)
	{
		v[i] = read();
		while (s.size() && v[i] > v[s.top()])
		{
			f[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", f[i]);
	}
	return 0;
}