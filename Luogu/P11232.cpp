#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Area
{
    int l, r;
    bool operator<(const Area &oth) const
    {
        return r < oth.r;
    }
};
vector<Area> as;
int p[MX], d[MX], v0[MX], a[MX];
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        as.clear();
        int n, m, len, v;
        cin >> n >> m >> len >> v;
        v *= v;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v0[i] >> a[i];
            v0[i] *= v0[i], a[i] *= 2;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++) // 每個超速車都有一個超速區段
        {
            int l = lower_bound(p + 1, p + 1 + m, d[i]) - p, r = m;
            if (l > m)
            {
                continue;
            }
            if (a[i] > 0)
            {
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    (v < v0[i] + a[i] * (p[mid] - d[i])) ? (r = mid - 1) : (l = mid + 1);
                }
                if (l <= m)
                {
                    as.emplace_back(Area{l, m});
                }
            }
            else if (a[i] < 0 && v0[i] > v)
            {
                int st = l;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    (v < v0[i] + a[i] * (p[mid] - d[i])) ? (l = mid + 1) : (r = mid - 1);
                }
                if (r >= st)
                {
                    as.emplace_back(Area{st, r});
                }
            }
            else if (a[i] == 0 && v0[i] > v)
            {
                as.emplace_back(Area{l, r});
            }
        }
        cout << as.size() << ' ';
        sort(as.begin(), as.end());
        int now = -1, res = 0;
        for (Area ar : as) // 貪心,排序後右端點儘可能靠右才能覆蓋更多區段
        {
            if (now >= ar.l)
            {
                continue;
            }
            res++, now = ar.r;
        }
        cout << m - res << endl;
    }
    return 0;
}