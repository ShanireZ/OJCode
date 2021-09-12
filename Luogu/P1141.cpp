#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    char num;
    int ansx, ansy, ans;
};
Node ns[1005][1005];
queue<int> qx, qy;
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ns[i][j].num;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (ns[x][y].ansx != 0)
        {
            cout << ns[ns[x][y].ansx][ns[x][y].ansy].ans << endl;
            continue;
        }
        int cnt = 1;
        qx.push(x), qy.push(y);
        ns[x][y].ansx = x, ns[x][y].ansy = y;
        while (qx.size() != 0)
        {
            int sx = qx.front(), sy = qy.front();
            qx.pop(), qy.pop();
            for (int j = 0; j < 4; j++)
            {
                int fx = sx + ms[j][0], fy = sy + ms[j][1];
                if (ns[fx][fy].ansx != 0)
                {
                    continue;
                }
                if (fx > 0 && fx <= n && fy > 0 && fy <= n && ns[fx][fy].num != ns[sx][sy].num)
                {
                    ns[fx][fy].ansx = x, ns[fx][fy].ansy = y;
                    cnt++;
                    qx.push(fx), qy.push(fy);
                }
            }
        }
        ns[x][y].ans = cnt;
        cout << cnt << endl;
    }
    return 0;
}