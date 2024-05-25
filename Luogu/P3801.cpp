#include <algorithm>
#include <iostream>
using namespace std;
int h[100005], l[100005], sh[100005], sl[100005], n, m, q;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, int y)
{
    sh[x] = 1 - sh[x], sl[y] = 1 - sl[y];
    int k = (sh[x] == 0 ? -1 : 1);
    while (x <= n)
    {
        h[x] += k;
        x += lowbit(x);
    }
    k = (sl[y] == 0 ? -1 : 1);
    while (y <= m)
    {
        l[y] += k;
        y += lowbit(y);
    }
}
pair<int, int> query(int x, int y)
{
    pair<int, int> ans = make_pair(0, 0);
    while (x)
    {
        ans.first += h[x];
        x -= lowbit(x);
    }
    while (y)
    {
        ans.second += l[y];
        y -= lowbit(y);
    }
    return ans;
}
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++)
    {
        int op, x1, y1, x2, y2;
        cin >> op >> x1 >> y1;
        if (op == 1)
        {
            edit(x1, y1);
        }
        else
        {
            cin >> x2 >> y2;
            pair<int, int> ans1 = query(x2, y2), ans2 = query(x1 - 1, y1 - 1);
            long long x = x2 - x1 + 1, y = y2 - y1 + 1;
            long long cx = ans1.first - ans2.first, cy = ans1.second - ans2.second;
            cout << cx * y + cy * x - 2 * cx * cy << endl; // 容斥
        }
    }
    return 0;
}