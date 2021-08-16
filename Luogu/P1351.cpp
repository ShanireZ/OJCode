#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int read();
struct Node
{
    int v;
    vector<int> to;
};
Node ns[200005];
int p = 10007;
int main()
{
    int n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        ns[u].to.push_back(v);
        ns[v].to.push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        ns[i].v = read();
    }
    long long tot = 0, maxv = 0;
    for (int i = 1; i <= n; i++) //枚举每个中转点
    {
        long long max1 = 0, max2 = 0;
        long long totj = 0, tot2j = 0;
        for (int j = 0; j < ns[i].to.size(); j++)
        {
            int id = ns[i].to[j];
            if (ns[id].v >= max1)
            {
                max2 = max1;
                max1 = ns[id].v;
            }
            else if (ns[id].v > max2 && ns[id].v < max1)
            {
                max2 = ns[id].v;
            }
            totj += ns[id].v;
            tot2j += ns[id].v * ns[id].v;
        }
        maxv = max(maxv, max1 * max2);
        tot = (tot + (totj * totj - tot2j) % p) % p;
    }
    printf("%lld %lld", maxv, tot);
    return 0;
}
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