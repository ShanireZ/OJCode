#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>, bool> mp;
struct PT
{
    int x, y;
};
PT pts[400005];
int mx[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}}, px[400005], py[400005], n, m, k;
long long qzx[400005], qzy[400005], ans;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> px[i] >> py[i];
        pts[i] = {px[i], py[i]}, mp[{px[i], py[i]}] = true;
    }
    sort(px + 1, px + k + 1), sort(py + 1, py + k + 1);
    for (int i = 1; i <= k; i++)
    {
        qzx[i] = qzx[i - 1] + px[i], qzy[i] = qzy[i - 1] + py[i];
    }
    pts[k + 1] = {1, 1}, pts[k + 2] = {n, m}, pts[k + 3] = {1, m}, pts[k + 4] = {n, 1};
    for (int i = 1; i <= k + 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int x = pts[i].x + mx[j][0], y = pts[i].y + mx[j][1];
            if (x < 1 || x > n || y < 1 || y > m || mp[{x, y}])
            {
                continue;
            }
            long long posx = upper_bound(px + 1, px + 1 + k, x) - px - 1;
            long long posy = upper_bound(py + 1, py + 1 + k, y) - py - 1;
            long long res = (posx * x - qzx[posx]) + (qzx[k] - qzx[posx] - (k - posx) * x);
            res += (posy * y - qzy[posy]) + (qzy[k] - qzy[posy] - (k - posy) * y);
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}