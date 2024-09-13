#include <algorithm>
#include <iostream>
using namespace std;
int prim[100005], vis[100005], pos;
int main()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && i * prim[j] <= 100000; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        long long n, k, ans = 1;
        cin >> n >> k;
        for (int i = 1; i <= pos; i++)
        {
            int t = 0;
            while (n % prim[i] == 0)
            {
                n /= prim[i], t++;
            }
            if (t >= k)
            {
                while (t--)
                {
                    ans *= prim[i];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}