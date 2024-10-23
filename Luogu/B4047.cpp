#include <algorithm>
#include <iostream>
using namespace std;
int vis[10005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int opt, l, r;
        cin >> opt >> l >> r;
        l = l * 2 - 1, r = r * 2 - 1;
        if (opt == 1)
        {
            l += 1, r -= 1;
        }
        for (int j = l; j <= r; j++)
        {
            vis[j] = 1;
        }
    }
    int res1 = 0, res2 = 0;
    for (int i = 1; i < n * 2; i++)
    {
        if (vis[i] == 1)
        {
            continue;
        }
        i % 2 == 1 ? res1++ : res2++;
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}