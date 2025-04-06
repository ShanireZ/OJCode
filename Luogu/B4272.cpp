#include <algorithm>
#include <iostream>
using namespace std;
int l, r, pos, ans, prim[10000005], vis[10000005], res[10000005];
int main()
{
    cin >> l >> r;
    for (int i = 2; i <= r; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i, res[i] = 1;
        }
        for (int j = 1; j <= pos && prim[j] * i <= r; j++)
        {
            vis[prim[j] * i] = 1;
            res[prim[j] * i] = res[i] + 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    for (int i = l; i <= r; i++)
    {
        ans = max(ans, res[i]);
    }
    cout << ans << endl;
    return 0;
}