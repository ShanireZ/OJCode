#include <algorithm>
#include <iostream>
using namespace std;
int n, ans[8005], vis[8005];
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> ans[i];
    }
    fill(vis + 1, vis + 1 + n, 1);
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1, c = 0; j <= n; j++)
        {
            c += vis[j];
            if (c == ans[i] + 1 && vis[j])
            {
                vis[j] = 0, ans[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}