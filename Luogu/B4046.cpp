#include <algorithm>
#include <iostream>
using namespace std;
int n, m, r, k, pos, rpos, vis[10005], prim[10005], res[10005];
int main()
{
    cin >> n >> m >> r >> k;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
            if (i % m == r)
            {
                res[++rpos] = i;
            }
        }
        for (int j = 1; j <= pos && prim[j] * i <= n; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    cout << (k > rpos ? -1 : res[rpos - k + 1]) << endl;
    return 0;
}