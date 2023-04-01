#include <iostream>
using namespace std;
int vis[100005], prim[100005], pos;
int main()
{
    int n, ans = 0;
    cin >> n;
    prim[0] = -1;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
            if (prim[pos] - prim[pos - 1] == 2)
            {
                ans++;
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
    cout << ans << "\n";
    return 0;
}