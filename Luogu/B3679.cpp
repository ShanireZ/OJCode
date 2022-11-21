#include <iostream>
using namespace std;
struct Node
{
    int x, y, bn;
};
Node ns[1005];
int main()
{
    int n, k, t;
    cin >> n >> k >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = 1; j <= n; j++)
        {
            if (ns[j].x == x && ns[j].y == y)
            {
                ns[j].bn = 1;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        int maxd = 0, id = 0;
        for (int j = 1; j <= n; j++)
        {
            int dis = (x - ns[j].x) * (x - ns[j].x) + (y - ns[j].y) * (y - ns[j].y);
            if (dis > maxd)
            {
                maxd = dis, id = j;
            }
        }
        if (ns[id].bn == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}