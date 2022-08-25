#include <iostream>
#include <vector>
using namespace std;
struct SegH
{
    int y, x1, x2;
};
vector<SegH> h;
struct SegZ
{
    int x, y1, y2;
};
vector<SegZ> z;
int n, es[255][255], back[255], vis[255];
bool dfs(int now, int turn)
{
    if (vis[now] == turn)
    {
        return false;
    }
    vis[now] = turn;
    for (int i = 1; i <= int(z.size()); i++)
    {
        if (es[now][i] == 0)
        {
            continue;
        }
        if (back[i] == 0 || dfs(back[i], turn))
        {
            back[i] = now;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            swap(x1, x2);
        }
        if (y1 > y2)
        {
            swap(y1, y2);
        }
        (x1 == x2) ? z.push_back(SegZ{x1, y1, y2}) : h.push_back(SegH{y1, x1, x2});
    }
    for (int i = 0; i < int(h.size()); i++)
    {
        for (int j = 0; j < int(z.size()); j++)
        {
            if (z[j].x <= h[i].x2 && z[j].x >= h[i].x1 && h[i].y <= z[j].y2 && h[i].y >= z[j].y1)
            {
                es[i + 1][j + 1] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= int(h.size()); i++)
    {
        ans += dfs(i, i);
    }
    cout << n - ans << endl;
    return 0;
}