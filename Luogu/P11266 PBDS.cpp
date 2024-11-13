#include <bits/extc++.h>
#include <iostream>
using namespace std;
__gnu_pbds::priority_queue<int, greater<int>> q[1000005];
__gnu_pbds::priority_queue<int, greater<int>>::point_iterator its[1000005];
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        its[i] = q[i].push(read());
    }
    for (int i = 1; i <= m; i++)
    {
        int opt = read(), x = read();
        if (opt == 0)
        {
            int y = read();
            q[x].erase(its[y]);
        }
        else if (opt == 1)
        {
            printf("%d\n", q[x].top());
        }
        else if (opt == 2)
        {
            int y = read();
            q[x].join(q[y]);
        }
        else
        {
            int y = read(), z = read();
            q[x].modify(its[y], z);
        }
    }
    return 0;
}