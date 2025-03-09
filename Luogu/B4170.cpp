#include <algorithm>
#include <iostream>
using namespace std;
int vis[1000005], prim[1000005], pos, T;
int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && prim[j] * i <= 1000000; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        long long ans = n;
        for (int i = 1; i <= pos && prim[i] <= n; i++)
        {
            if (n % prim[i] == 0)
            {
                ans = prim[i];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}