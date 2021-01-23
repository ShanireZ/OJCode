#include <iostream>
#include <deque>
#include <cctype>
#include <cstdio>
using namespace std;
deque<int> q;
int v[2000005];
int read()
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
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main()
{
    int n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        v[i] = read();
        while (q.size() && v[q.back()] <= v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        while (q.front() < i - k + 1)
        {
            q.pop_front();
        }
        if (i >= k)
        {
            printf("%d\n",v[q.front()]);
        }
    }
    return 0;
}