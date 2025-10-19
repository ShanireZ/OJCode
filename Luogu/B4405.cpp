#include <algorithm>
#include <iostream>
using namespace std;
int n, m, cnt, a, vis[100005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (vis[a] == 0)
        {
            vis[a] = 1, cnt++;
        }
        if (a + 1 <= m && vis[a + 1] == 0)
        {
            vis[a + 1] = 1, cnt++;
        }
    }
    if (cnt == m)
    {
        cout << "Accepted" << endl;
        return 0;
    }
    cout << m - cnt << endl;
    for (int i = 1; i <= m; i++)
    {
        if (vis[i] == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}