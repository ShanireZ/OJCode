#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
struct Node
{
    double x, y;
    bool operator<(const Node &oth) const
    {
        return x == oth.x ? y < oth.y : x < oth.x;
    }
};
Node ns[105];
int q[105], n, ed, id;
double sd(Node a, Node b, Node c)
{
    Node g = Node{b.x - a.x, b.y - a.y};
    Node h = Node{c.x - a.x, c.y - a.y};
    return g.x * h.y - g.y * h.x;
}
double dis(Node a, Node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Andrew()
{
    sort(ns + 1, ns + n + 1);
    q[1] = 1, q[2] = 2, ed = 3;
    for (int i = 3; i <= n; i++)
    {
        while (q[ed - 1] != 1 && sd(ns[q[ed - 2]], ns[q[ed - 1]], ns[i]) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
    q[ed++] = n - 1;
    for (int i = n - 2; i >= 1; i--)
    {
        while (q[ed - 1] != n && sd(ns[q[ed - 2]], ns[q[ed - 1]], ns[i]) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
}
double xzkk()
{
    int pos = 2;
    double ans = 1e15;
    for (int i = 2; i < ed; i++)
    {
        while (sd(ns[q[i - 1]], ns[q[i]], ns[q[pos]]) < sd(ns[q[i - 1]], ns[q[i]], ns[q[pos + 1]]))
        {
            pos == ed - 2 ? pos = 1 : pos = pos + 1;
        }
        ans = min(ans, abs(sd(ns[q[i - 1]], ns[q[i]], ns[q[pos]]) / dis(ns[q[i - 1]], ns[q[i]])));
    }
    return ans;
}
int main()
{
    cin >> n;
    while (n)
    {
        id++;
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].x >> ns[i].y;
        }
        Andrew();
        double ans = xzkk();
        cout << "Case " << id << ": " << fixed << setprecision(2) << ans << endl;
        cin >> n;
    }
    return 0;
}