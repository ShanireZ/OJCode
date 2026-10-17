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
    double pos = -1e9; // 為了覆蓋當前區域的海島，在最遠可以在pos處架設一個雷達
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].l > pos) // 當前的雷達無法覆蓋海島i
        {
            cnt++, pos = ns[i].r; // 為了覆蓋海島i，架設一個雷達在r處
        }
    }
    cout << cnt << "\n";
    return 0;
}
// TAG: 數學 幾何 貪心