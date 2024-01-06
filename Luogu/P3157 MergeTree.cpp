#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int lc, rc;
    vector<int> v;
};
Node ns[400005];
int n, m, pos, root, a[100005];
long long ans;
void init()
{
    for (int i = 1; i <= pos; i++)
    {
        ns[i].v.clear();
        ns[i].lc = ns[i].rc = 0;
    }
    pos = root = ans = 0;
}
void maketree(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v.push_back(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid), maketree(ns[now].rc, mid + 1, r);
    int szl = ns[ns[now].lc].v.size(), szr = ns[ns[now].rc].v.size();
    for (int i = 0, j = 0; i + j < szl + szr;)
    {
        if (j == szr || (i < szl && ns[ns[now].lc].v[i] < ns[ns[now].rc].v[j]))
        {
            ns[now].v.push_back(ns[ns[now].lc].v[i++]);
        }
        else
        {
            ns[now].v.push_back(ns[ns[now].rc].v[j++]), ans += (szl - i);
        }
    }
}
void findk(int now, int l, int r, int k)
{
    ns[now].v.erase(lower_bound(ns[now].v.begin(), ns[now].v.end(), k));
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    int p = lower_bound(ns[ns[now].lc].v.begin(), ns[ns[now].lc].v.end(), k) - ns[ns[now].lc].v.begin();
    if (p < (int)ns[ns[now].lc].v.size() && ns[ns[now].lc].v[p] == k)
    {
        findk(ns[now].lc, l, mid, k);
        p = lower_bound(ns[ns[now].rc].v.begin(), ns[ns[now].rc].v.end(), k) - ns[ns[now].rc].v.begin();
        ans -= p;
    }
    else
    {
        findk(ns[now].rc, mid + 1, r, k);
        ans -= (int)ns[ns[now].lc].v.size() - p;
    }
}
int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        maketree(root, 1, n);
        for (int i = 1; i <= m; i++)
        {
            printf("%lld\n", ans);
            int num;
            scanf("%d", &num);
            findk(root, 1, n, num);
        }
    }
    return 0;
}