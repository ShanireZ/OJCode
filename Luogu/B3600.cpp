#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int lj[305][305], gl[305][305];
vector<int> to[305][2], from[305][2];
vector<int> za, zb, zc, fa, fb, fc;
int main()
{
    int n, m, t1, t2, cb = 0, zh = 0;
    cin >> n >> m >> t1 >> t2;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v;
        zh += (u == v);
        if (t2 == 1) // 有权
        {
            cin >> w;
            cb += (lj[u][v] != 0);
            lj[u][v] = w;
            to[u][0].push_back(v), to[u][1].push_back(w);
            from[v][0].push_back(u), from[v][1].push_back(w);
            if (t1 == 0) // 无向
            {
                lj[v][u] = w;
                to[v][0].push_back(u), to[v][1].push_back(w);
                from[u][0].push_back(v), from[u][1].push_back(w);
            }
        }
        else
        {
            cb += (lj[u][v] != 0);
            lj[u][v] = 1, gl[u][i] = 1;
            to[u][0].push_back(v), from[v][0].push_back(u);
            if (t1 == 0) // 无向
            {
                lj[v][u] = 1, gl[v][i] = 1;
                to[v][0].push_back(u), from[u][0].push_back(v);
            }
            else
            {
                gl[v][i] = -1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        za.push_back(zb.size() + 1);
        for (int x : to[i][0])
        {
            zb.push_back(x);
        }
        if (t2 == 1)
        {
            for (int x : to[i][1])
            {
                zc.push_back(x);
            }
        }
        fa.push_back(fb.size() + 1);
        for (int x : from[i][0])
        {
            fb.push_back(x);
        }
        if (t2 == 1)
        {
            for (int x : from[i][1])
            {
                fc.push_back(x);
            }
        }
    }
    za.push_back(zb.size() + 1), fa.push_back(fb.size() + 1);
    if (cb == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << lj[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (t2 == 0 && zh == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << gl[i][j] << " ";
            }
            cout << endl;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (int)to[i][0].size(); j++)
        {
            cout << to[i][0][j] << " ";
            if (t2 == 1)
            {
                cout << to[i][1][j] << " ";
            }
        }
        cout << endl;
    }
    for (int x : za)
    {
        cout << x << " ";
    }
    cout << endl;
    for (int x : zb)
    {
        cout << x << " ";
    }
    cout << endl;
    if (t2 == 1)
    {
        for (int x : zc)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    if (t1)
    {
        for (int x : fa)
        {
            cout << x << " ";
        }
        cout << endl;
        for (int x : fb)
        {
            cout << x << " ";
        }
        cout << endl;
        if (t2 == 1)
        {
            for (int x : fc)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}