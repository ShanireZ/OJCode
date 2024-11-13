#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
multiset<int> s[1000005];
int a[1000005];
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
        a[i] = read();
        s[i].emplace(a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int opt = read(), x = read();
        if (opt == 0)
        {
            int y = read();
            s[x].erase(s[x].find(a[y]));
        }
        else if (opt == 1)
        {
            printf("%d\n", *s[x].begin());
        }
        else if (opt == 2)
        {
            int y = read();
            if (s[x].size() < s[y].size())
            {
                swap(s[x], s[y]);
            }
            for (int j : s[y])
            {
                s[x].emplace(j);
            }
        }
        else
        {
            int y = read(), z = read();
            s[x].erase(s[x].find(a[y]));
            a[y] = z, s[x].emplace(z);
        }
    }
    return 0;
}