#include <algorithm>
#include <iostream>
using namespace std;
int prim[10005], vis[10005], pos, ans, s;
int main()
{
    cin >> s;
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= s; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
            for (int j = i + i; j <= s; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        if (vis[s - prim[i]] == 0)
        {
            ans = max(ans, prim[i] * (s - prim[i]));
        }
    }
    cout << ans << endl;
    return 0;
}