#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    double l, r;
    bool operator<(const Node &a) const
    {
        return r < a.r;
    }
};
Node ns[1005];
int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y > d)
        {
            cout << -1 << endl;
            return 0;
        }
        double dis = sqrt(d * d - y * y);
        ns[i].l = x - dis, ns[i].r = x + dis;
    }
    sort(ns + 1, ns + n + 1);
    double pos = -1e9; // 为了覆盖当前区域的海岛，在最远可以在pos处架设一个雷达
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].l > pos) // 当前的雷达无法覆盖海岛i
        {
            cnt++, pos = ns[i].r; // 为了覆盖海岛i，架设一个雷达在r处
        }
    }
    cout << cnt << "\n";
    return 0;
}
// TAG: 数学 几何 贪心