#include <iostream>
#include <algorithm>
using namespace std;
//* 先將所有奶牛離散化，其座標範圍將離散至1~n
//* 對於每一個可以圍欄的非空奶牛子集，考慮包圍該子集的最小尺寸的矩形。
//* 這個矩形的四個邊上必須都包含一頭奶牛。如果我們直接枚舉，那麼時間複雜度是n^4，AC需要最多n^2的方案。
//* 假設我們將牛a=(xa,ya)和b=(xb,yb)固定在矩形的底邊和頂邊。
//* 矩形左側的牛c一定滿足1<=yc≤min(ya,yb)，且xa≤xc≤xb。我們據此能求出牛c的情況數。
//* 同理，矩形右側的牛d必須滿足max(ya,yb)≤yd<=n，且ya≤yd≤yb。我們據此能求出牛c的情況數。
//* 那麼以牛a和牛b作為頂邊和底邊能形成的情況數為 牛c的情況數 * 牛d的情況數。
//* 我們可以用二維前綴和來計算每個區域的牛的數量，以便以O(1)的複雜度求出情況數。
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