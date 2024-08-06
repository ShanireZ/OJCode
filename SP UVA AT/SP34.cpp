#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;
struct Node
{
    double x, y, dis;
};
Node ns[1005];
int n, x, y;
mt19937 gen(time(0));
double ctdis(Node a)
{
    double res = 1e18;
    for (int i = 1; i <= n; i++)
    {
        double d = (a.x - ns[i].x) * (a.x - ns[i].x) + (a.y - ns[i].y) * (a.y - ns[i].y);
        res = min(res, d);
    }
    return res;
}
Node SA()
{
    Node res = Node{gen() % (x + 1), gen() % (y + 1), 0};
    res.dis = ctdis(res);
    double t = 10000;
    Node lst = res;
    while (t >= 1e-15)
    {
        double ex = gen() % (x + 1) / 10.0, ey = gen() % (y + 1) / 10.0;
        int fx = gen() % 3 - 1, fy = gen() % 3 - 1;
        Node now = Node{min(max(lst.x + ex * fx, 0.0), 1.0 * x), min(max(lst.y + ey * fy, 0.0), 1.0 * y), 0};
        now.dis = ctdis(now);
        if (now.dis > res.dis)
        {
            res = lst = now;
        }
        else if (exp((now.dis - res.dis) / t) * 100 > gen() % 100)
        {
            lst = now;
        }
        t = 0.99 * t;
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> x >> y >> n;
        Node ans = Node{0, 0, 0};
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].x >> ns[i].y;
            ans.x += ns[i].x, ans.y += ns[i].y;
        }
        ans.x /= n, ans.y /= n;
        ans.dis = ctdis(ans);
        for (int i = 1; i <= 1000; i++)
        {
            Node res = SA();
            if (res.dis > ans.dis)
            {
                ans = res;
            }
        }
        cout << "The safest point is (";
        cout << fixed << setprecision(1) << ans.x << ", " << ans.y;
        cout << ").\n";
    }
    return 0;
}