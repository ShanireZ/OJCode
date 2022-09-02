#include <cmath>
#include <iostream>
using namespace std;
struct Ore
{
    int w, v;
};
Ore ors[200005];
struct Area
{
    int x, y;
};
Area as[200005];
int n, m;
long long s, cnt[200005], tot[200005];
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> ors[i].w >> ors[i].v;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> as[i].x >> as[i].y;
    }
    int l = 0, r = 1000000;
    long long ans = 1e18;
    while (l <= r)
    {
        long long now = 0;
        int mid = (l + r) / 2;
        for (int i = 1; i <= n; i++)
        {
            cnt[i] = cnt[i - 1], tot[i] = tot[i - 1];
            if (ors[i].w >= mid)
            {
                cnt[i]++, tot[i] += ors[i].v;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            int x = as[i].x, y = as[i].y;
            now += (cnt[y] - cnt[x - 1]) * (tot[y] - tot[x - 1]);
        }
        if (now < s)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        ans = min(ans, abs(now - s));
    }
    cout << ans << endl;
    return 0;
}