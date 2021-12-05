#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int dis[50][50];
int main()
{
    int n, m, k;
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        dis[a][b] = dis[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        set<int> x;
        for (int k = 1; k <= n; k++)
        {
            if (dis[a][b] == dis[a][k] + dis[k][b])
            {
                x.insert(k);
            }
        }
        for (auto p = x.begin(); p != x.end(); p++)
        {
            cout << *p << " ";
        }
        cout << endl;
    }
    return 0;
}