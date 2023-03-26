#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> fz[2];
int vis[100005], nxt[100005], pre[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        fz[0].push_back(i * i);
    }
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            fz[1].push_back(i);
        }
        for (int j = 0; j < (int)fz[1].size() && i * fz[1][j] <= n; j++)
        {
            vis[i * fz[1][j]] = 1;
            if (i % fz[1][j] == 0)
            {
                break;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        nxt[i] = i + 1, pre[i] = i - 1;
    }
    int mode = 0, cnt = 0;
    while (cnt != n - 1)
    {
        int now = nxt[0], pos = 0, no = 1;
        while (pos < (int)fz[mode].size() && now != n + 1)
        {
            if (no == fz[mode][pos])
            {
                nxt[pre[now]] = nxt[now], pre[nxt[now]] = pre[now];
                pos++, cnt++;
            }
            now = nxt[now], no++;
        }
        mode = !mode;
    }
    cout << nxt[0];
    return 0;
}