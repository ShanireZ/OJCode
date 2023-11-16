#include <algorithm>
#include <iostream>
using namespace std;
long long prim[1000005], vis[1000005], pos, n, ok;
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
    cin >> n;
    for (int i = 1; prim[i] * prim[i] <= n; i++)
    {
        int cnt = 0;
        while (n % prim[i] == 0)
        {
            cnt++;
            n /= prim[i];
        }
        if (cnt)
        {
            if (ok)
            {
                cout << " * ";
            }
            ok = 1;
            cout << prim[i];
            if (cnt > 1)
            {
                cout << "^" << cnt;
            }
        }
    }
    if (n)
    {
        if (ok)
        {
            cout << " * ";
        }
        cout << n;
    }
    return 0;
}