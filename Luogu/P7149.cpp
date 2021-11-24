#include <iostream>
#include <algorithm>
using namespace std;
//* 先将所有奶牛离散化，其坐标范围将离散至1~n
//* 对于每一个可以围栏的非空奶牛子集，考虑包围该子集的最小尺寸的矩形。
//* 这个矩形的四个边上必须都包含一头奶牛。如果我们直接枚举，那么时间复杂度是n^4，AC需要最多n^2的方案。
//* 假设我们将牛a=(xa,ya)和b=(xb,yb)固定在矩形的底边和顶边。
//* 矩形左侧的牛c一定满足1<=yc≤min(ya,yb)，且xa≤xc≤xb。我们据此能求出牛c的情况数。
//* 同理，矩形右侧的牛d必须满足max(ya,yb)≤yd<=n，且ya≤yd≤yb。我们据此能求出牛c的情况数。
//* 那么以牛a和牛b作为顶边和底边能形成的情况数为 牛c的情况数 * 牛d的情况数。
//* 我们可以用二维前缀和来计算每个区域的牛的数量，以便以O(1)的复杂度求出情况数。
struct Node
{
    int x, y;
};
bool cmpx(Node a, Node b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }
    return a.x < b.x;
}
bool cmpy(Node a, Node b)
{
    if (a.y == b.y)
    {
        return a.x < b.x;
    }
    return a.y < b.y;
}
Node ns[3000];
int sumn[3000][3000];
long long query(int x1, int y1, int x2, int y2)
{
    return sumn[x2][y2] - sumn[x2][y1 - 1] - sumn[x1 - 1][y2] + sumn[x1 - 1][y1 - 1];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    sort(ns + 1, ns + 1 + n, cmpx);
    for (int i = 1; i <= n; i++)
    {
        ns[i].x = i;
    }
    sort(ns + 1, ns + 1 + n, cmpy);
    for (int i = 1; i <= n; i++)
    {
        ns[i].y = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x = ns[i].x, y = ns[i].y;
        sumn[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sumn[i][j] = sumn[i][j] + sumn[i - 1][j] + sumn[i][j - 1] - sumn[i - 1][j - 1];
        }
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int x1 = min(ns[i].x, ns[j].x);
            int x2 = max(ns[i].x, ns[j].x);
            int y1 = min(ns[i].y, ns[j].y);
            int y2 = max(ns[i].y, ns[j].y);
            ans += query(x1, 1, x2, y1) * query(x1, y2, x2, n);
        }
    }
    cout << ans;
    return 0;
}