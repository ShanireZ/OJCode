#include <cstdio>
#include <queue>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
priority_queue<int> a;
queue<int> a1, a2;
int check()
{
    int ans, x = -2e9, x1 = -2e9, x2 = -2e9;
    if (a.size())
    {
        x = a.top();
    }
    if (a1.size())
    {
        x1 = a1.front();
    }
    if (a2.size())
    {
        x2 = a2.front();
    }
    if (x >= x1 && x >= x2)
    {
        ans = x;
        a.pop();
    }
    else if (x1 >= x && x1 >= x2)
    {
        ans = x1;
        a1.pop();
    }
    else if (x2 >= x && x2 >= x1)
    {
        ans = x2;
        a2.pop();
    }
    return ans;
}
int main()
{
    int n = read(), m = read(), q = read(), u = read(), v = read(), t = read();
    double p = 1.0 * u / v;
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        a.push(x);
    }
    for (int i = 1; i <= m; i++)
    {
        int now = check();
        now += (i - 1) * q;
        if (i % t == 0)
        {
            printf("%d ", now);
        }
        int n1 = now * p;
        int n2 = now - n1;
        a1.push(n1 - q * i), a2.push(n2 - q * i);
    }
    printf("\n");
    for (int i = 1; i <= n + m; i++)
    {
        int now = check();
        if (i % t == 0)
        {
            printf("%d ", now + m * q);
        }
    }
    return 0;
}