#include <cstring>
#include <iostream>
using namespace std;
int t, n, sdu[55], goh[55], es[55][55], vis[55], back[55];
bool dfs(int now, int turn)
{
    if (vis[now] == turn)
    {
        return false;
    }
    vis[now] = turn;
    for (int i = 1; i <= n; i++)
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
    cin >> t;
    while (t--)
    {
        memset(sdu, 0, sizeof(sdu));
        memset(goh, 0, sizeof(goh));
        memset(es, 0, sizeof(es));
        memset(back, 0, sizeof(back));
        memset(vis, 0, sizeof(vis));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> sdu[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> goh[i];
            if (sdu[i] == 0)
            {
                goh[i] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (sdu[i] == 1 && goh[i] == 0)
            {
                es[i][i] = 1;
            }
            for (int j = 1; j <= n; j++)
            {
                int x;
                cin >> x;
                if (x == 1 && sdu[j] == 1 && goh[i] == 0)
                {
                    es[i][j] = 1;
                }
            }
        }
        int trig = 0;
        for (int i = 1; i <= n; i++)
        {
            if (goh[i] == 1)
            {
                continue;
            }
            if (dfs(i, i) == false)
            {
                trig = 1;
                cout << "T_T" << endl;
                break;
            }
        }
        if (trig)
        {
            continue;
        }
        cout << "^_^" << endl;
    }
    return 0;
}