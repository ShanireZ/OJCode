#include <algorithm>
#include <iostream>
using namespace std;
int T, n, k, tr[100005], a[100005], ls[100005];
void edit(int now, int ex)
{
    while (now <= n)
    {
        tr[now] += ex;
        now += (now & -now);
    }
}
int query(int now)
{
    int cnt = 0;
    while (now)
    {
        cnt += tr[now];
        now -= (now & -now);
    }
    return cnt;
}
bool check(long long x)
{
    long long cnt = 0, g = 1, st = 1;
    edit(a[1], 1);
    for (int i = 2; i <= n; i++)
    {
        int c = (i - st) - query(a[i]);
        if (cnt + c > x)
        {
            for (int j = st; j < i; j++)
            {
                edit(a[j], -1);
            }
            st = i, cnt = 0, g++;
        }
        else
        {
            cnt += c;
        }
        edit(a[i], 1);
    }
    for (int i = st; i <= n; i++)
    {
        edit(a[i], -1);
    }
    return g <= k ? 1 : 0;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ls[i] = a[i];
        }
        sort(ls + 1, ls + n + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = lower_bound(ls + 1, ls + 1 + n, a[i]) - ls;
        }
        long long l = 0, r = 1e10;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            check(mid) ? r = mid - 1 : l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}