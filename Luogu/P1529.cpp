#include <iostream>
#include <algorithm>
using namespace std;
int g[100][100];
int trans(char x)
{
    int ans;
    if (x >= 'a' && x <= 'z')
    {
        ans = x - 'a' + 1;
    }
    else
    {
        ans = x - 'A' + 1 + 26;
    }
    return ans;
}
int main()
{
    int p;
    cin >> p;
    for (int i = 1; i <= 52; i++)
    {
        for (int j = i + 1; j <= 52; j++)
        {
            g[i][j] = g[j][i] = 0x3f3f3f3f;
        }
        g[i][i] = 0;
    }
    for (int i = 1; i <= p; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        int a = trans(u), b = trans(v);
        g[a][b] = g[b][a] = min(g[a][b], w);
    }
    for (int k = 1; k <= 52; k++)
    {
        for (int i = 1; i <= 52; i++)
        {
            for (int j = 1; j <= 52; j++)
            {
                if (g[i][k] != 0x3f3f3f3f || g[k][j] != 0x3f3f3f3f)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
    int ans = 27;
    for (int i = 27; i < 52; i++)
    {
        if (g[i][52] < g[ans][52])
        {
            ans = i;
        }
    }
    cout << (char)(ans - 26 - 1 + 'A') << " " << g[ans][52];
    return 0;
}