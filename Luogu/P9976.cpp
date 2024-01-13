#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 200005
struct Node
{
    long long h, a, g;
    bool operator<(const Node &oth) const
    {
        return g > oth.g;
    }
};
Node ns[MX];
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].h;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].a;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].g;
        }
        sort(ns + 1, ns + n + 1);
        long long l = 0, r = 1e9;
        for (int i = 2; i <= n; i++)
        {
            if (ns[i].h > ns[i - 1].h && ns[i].a < ns[i - 1].a)
            {
                long long t = ceil(1.0 * (ns[i].h - ns[i - 1].h) / (ns[i - 1].a - ns[i].a)); // 多少天后一样高
                r = min(r, t - 1);                                                           // 前一天肯定i高
            }
            else if (ns[i].h <= ns[i - 1].h && ns[i].a <= ns[i - 1].a)
            {
                l = r = -1;
                break;
            }
            else if (ns[i].h < ns[i - 1].h && ns[i].a > ns[i - 1].a)
            {
                long long t = ceil(1.0 * (ns[i - 1].h - ns[i].h + 1) / (ns[i].a - ns[i - 1].a)); // 多少天后更高
                l = max(l, t);
            }
            else if (ns[i].h == ns[i - 1].h && ns[i].a > ns[i - 1].a)
            {
                l = max(l, 1ll);
            }
            if (l > r)
            {
                l = r = -1;
                break;
            }
        }
        cout << l << endl;
    }
    return 0;
}
// TAG: USACO 模拟 贪心 枚举