#include <algorithm>
#include <iostream>
using namespace std;
int vis[1005];
int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cnt += vis[i];
        if (vis[i] == 0)
        {
            cout << i << " ";
        }
    }
    if (cnt == n)
    {
        cout << n << endl;
    }
    return 0;
}
// TAG: 模拟 GESP3