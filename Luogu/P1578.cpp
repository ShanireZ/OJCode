#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int x, y;
};
Node ns[5005];
bool cmpx(Node a, Node b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmpy(Node a, Node b)
{
    return a.y < b.y;
}
int main()
{
    int a, b, n, ans;
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    ns[n + 1] = Node{0, 0}, ns[n + 2] = Node{0, b};
    ns[n + 3] = Node{a, 0}, ns[n + 4] = Node{a, b};
    n += 4;
    sort(ns + 1, ns + n + 1, cmpx);
    for (int i = 1; i < n; i++) // 从左向右
    {
        int u = b, d = 0;
        for (int j = i + 1; j <= n; j++)
        {
            ans = max(ans, (u - d) * (ns[j].x - ns[i].x));
            ns[j].y > ns[i].y ? u = min(u, ns[j].y) : d = max(d, ns[j].y);
        }
    }
    for (int i = n; i > 1; i--) // 从右向左
    {
        int u = b, d = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            ans = max(ans, (u - d) * (ns[i].x - ns[j].x));
            ns[j].y > ns[i].y ? u = min(u, ns[j].y) : d = max(d, ns[j].y);
        }
    }
    sort(ns + 1, ns + n + 1, cmpy);
    for (int i = 1; i < n; i++) // 从下向上扫到左右边界的
    {
        ans = max(ans, a * (ns[i + 1].y - ns[i].y));
    }
    cout << ans << endl;
    return 0;
}
// TAG: 最大子矩形 扫描法 区间DP优化