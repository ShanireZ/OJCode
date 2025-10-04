#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int b[1005][1005], g[1005][1005], l[1005], r[1005], pos[1005], T, n;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        fill(l + 1, l + 1 + n, 0), fill(r + 1, r + 1 + n, 0);
        fill(pos + 1, pos + 1 + n, 1);
        for (int i = 1; i <= n; i++)
        {
            q.push(i), pos[i] = 1;
            for (int j = 1; j <= n; j++)
            {
                cin >> g[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int x;
                cin >> x;
                b[i][x] = j;
            }
        }
        while (q.size())
        {
            int now = q.front();
            q.pop();
            int nxt = g[now][pos[now]++];
            if (r[nxt] == 0 || b[nxt][now] < b[nxt][r[nxt]])
            {
                if (r[nxt])
                {
                    q.push(r[nxt]);
                }
                r[nxt] = now, l[now] = nxt;
            }
            else
            {
                q.push(now);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << l[i] << endl;
        }
        if (T)
        {
            cout << endl;
        }
    }
    return 0;
}