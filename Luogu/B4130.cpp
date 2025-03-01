#include <iostream>
using namespace std;
int vis[5000005], prim[5000005], pos, n, ans;
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
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
    for (int i = 2; i <= pos; i++)
    {
        ans = max(ans, prim[i] - prim[i - 1] - 1);
    }
    cout << max(n - prim[pos], ans) << endl;
    return 0;
}