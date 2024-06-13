#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int p1, p2, id, f;
};
Node ns[200005];
int a[50005], g[50005], n, m, npos;
long long ans[50005], c1[50005], c2[50005];
bool cmp(Node x, Node y)
{
    if (g[x.p1] == g[y.p1])
    {
        return x.p2 < y.p2;
    }
    return x.p1 < y.p1;
}
int main()
{
    cin >> n;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i] = (i - 1) / sz + 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ns[++npos] = Node{min(y1, y2), max(y1, y2), i, 1};
        ns[++npos] = Node{min(x1, x2) - 1, max(x1, x2) - 1, i, 1};
        ns[++npos] = Node{min(x1 - 1, y2), max(x1 - 1, y2), i, -1};
        ns[++npos] = Node{min(y1, x2 - 1), max(y1, x2 - 1), i, -1};
    }
    sort(ns + 1, ns + npos + 1, cmp);
    long long res = 0, p1 = 0, p2 = 0;
    for (int i = 1; i <= npos; i++)
    {
        while (p1 < ns[i].p1)
        {
            p1++;
            c1[a[p1]]++, res += c2[a[p1]];
        }
        while (p1 > ns[i].p1)
        {
            c1[a[p1]]--, res -= c2[a[p1]];
            p1--;
        }
        while (p2 < ns[i].p2)
        {
            p2++;
            c2[a[p2]]++, res += c1[a[p2]];
        }
        while (p2 > ns[i].p2)
        {
            c2[a[p2]]--, res -= c1[a[p2]];
            p2--;
        }
        ans[ns[i].id] += ns[i].f * res;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
// TAG: 莫队算法