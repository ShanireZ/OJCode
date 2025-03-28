#include <algorithm>
#include <iostream>
using namespace std;
int prim[100005], vis[100005], n, m, a, res;
int main()
{
    cin >> n >> m >> a;
    for (int i = 2; i <= n + m; i++)
    {
        if (vis[i] == 0)
        {
            prim[i] = i;
            for (int j = 2; j * i <= n + m; j++)
            {
                prim[j * i] = i, vis[j * i] = 1;
            }
        }
    }
    for (int i = n; i <= n + m; i++)
    {
        if (prim[i] <= a)
        {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}