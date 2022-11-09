#include <algorithm>
#include <cstdio>
using namespace std;
struct Node
{
    int t, v;
    bool operator<(const Node other) const
    {
        return v < other.v;
    }
};
Node ns[200005];
int read();
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n + m; i++)
    {
        (i <= n) ? ns[i].t = 1 : ns[i].t = 2;
        ns[i].v = read();
    }
    sort(ns + 1, ns + 1 + n + m);
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n + m; i++)
    {
        if (ns[i].t == 2)
        {
            cnt++;
        }
        else if (cnt > 0)
        {
            ans++;
            cnt--;
        }
    }
    printf("%d", ans);
    return 0;
}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}