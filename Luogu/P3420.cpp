#include <iostream>
using namespace std;
int n, ans, g[1000005];
int dfn(int x)
{
    return (x == g[x]) ? x : g[x] = dfn(g[x]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int fa;
        cin >> fa;
        int gi = dfn(i), gf = dfn(fa);
        g[gi] = gf;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == g[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}