#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
long long ans;
int n, m, num, p[MX], a[MX];
vector<int> v[MX];
int lowbit(int x)
{
    return x & -x;
}
int query(int pos, int x, int op) // 1~pos中:op=1小于x的个数 op=2大于x的个数
{
    int res = 0;
    for (int i = pos; i > 0; i -= lowbit(i))
    {
        if (op == 1)
        {
            res += lower_bound(v[i].begin(), v[i].end(), x) - v[i].begin();
        }
        else
        {
            res += v[i].end() - upper_bound(v[i].begin(), v[i].end(), x);
        }
    }
    return res;
}
void edit(int pos, int x, int op) // pos~n中:op=1插入 op=2删除
{
    for (int i = pos; i <= n; i += lowbit(i))
    {
        if (op == 1)
        {
            v[i].push_back(x);
        }
        else
        {
            v[i].erase(lower_bound(v[i].begin(), v[i].end(), x));
        }
    }
}
int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            edit(i, num, 1), p[num] = i, a[i] = num;
        }
        for (int i = 1; i <= n; i++)
        {
            sort(v[i].begin(), v[i].end());
            ans += query(i - 1, a[i], 2); // 前方大于num的个数
        }
        for (int i = 1; i <= m; i++)
        {
            printf("%lld\n", ans);
            scanf("%d", &num);
            edit(p[num], num, 2);
            ans -= query(p[num] - 1, num, 2);                // 前方大于num的个数
            ans -= query(n, num, 1) - query(p[num], num, 1); // 后方小于num的个数
        }
    }
    return 0;
}