#include <algorithm>
#include <iostream>
using namespace std;
int vis[1000005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, ans = 0;
        cin >> n;
        fill(vis + 1, vis + 1 + n, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if (a != i)
            {
                vis[min(a, i)]++, vis[max(a, i) + 1]--;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            vis[i] += vis[i - 1];
            ans += (vis[i] > 0);
        }
        cout << ans << endl;
    }
    return 0;
}