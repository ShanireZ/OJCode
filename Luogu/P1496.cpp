#include <algorithm>
#include <iostream>
using namespace std;
struct Area
{
    int l, r;
};
Area as[20005];
int pos[40005], t[40005];
int main()
{
    int n, cnt, ans = 0, now = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> as[i].l >> as[i].r;
        pos[++cnt] = as[i].l;
        pos[++cnt] = as[i].r;
    }
    sort(pos + 1, pos + 1 + cnt);
    cnt = unique(pos + 1, pos + 1 + cnt) - (pos + 1);
    for (int i = 1; i <= n; i++)
    {
        int l = lower_bound(pos + 1, pos + 1 + cnt, as[i].l) - pos;
        int r = lower_bound(pos + 1, pos + 1 + cnt, as[i].r) - pos;
        t[l]++, t[r]--;
    }
    for (int i = 1; i <= cnt; i++)
    {
        now += t[i];
        if (now)
        {
            ans += pos[i + 1] - pos[i];
        }
    }
    cout << ans << endl;
    return 0;
}