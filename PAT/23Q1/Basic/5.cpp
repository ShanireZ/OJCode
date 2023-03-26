#include <iostream>
using namespace std;
#define MX 20010
#define N 20000
int pre[MX], nxt[MX], sta[MX], t[MX];
int main()
{
    int k, n, m, c1 = 0, c2 = 0;
    cin >> k >> n >> m;
    pre[N + 3] = N + 1, nxt[N + 1] = N + 3;
    pre[N + 4] = N + 2, nxt[N + 2] = N + 4;
    for (int i = 1; i <= m; i++)
    {
        int now;
        cin >> now;
        if (sta[now] == 2) // done 检查是否在队列2
        {
            pre[nxt[now]] = pre[now], nxt[pre[now]] = nxt[now];
            pre[now] = pre[N + 4], nxt[pre[N + 4]] = now;
            pre[N + 4] = now, nxt[now] = N + 4;
        }
        else if (sta[now] == 1) // deone 检查是否在队列1
        {
            pre[nxt[now]] = pre[now], nxt[pre[now]] = nxt[now];
            pre[now] = pre[N + 3], nxt[pre[N + 3]] = now;
            pre[N + 3] = now, nxt[now] = N + 3;
            t[now]++;
            if (t[now] == k)
            {
                pre[N + 3] = pre[now], nxt[pre[now]] = N + 3, c1--;
                if (c2 == n) // done c2满了
                {
                    int x = nxt[N + 2];
                    t[x] = 0, sta[x] = 0;
                    nxt[N + 2] = nxt[x], pre[nxt[x]] = N + 2, c2--;
                }
                pre[now] = pre[N + 4], nxt[pre[N + 4]] = now;
                pre[N + 4] = now, nxt[now] = N + 4, c2++;
                sta[now] = 2, t[now] = 0;
            }
        }
        else
        {
            if (c1 == n) // done c1满了
            {
                int x = nxt[N + 1];
                t[x] = 0, sta[x] = 0;
                nxt[N + 1] = nxt[x], pre[nxt[x]] = N + 1, c1--;
            }
            pre[now] = pre[N + 3], nxt[pre[N + 3]] = now;
            pre[N + 3] = now, nxt[now] = N + 3, c1++;
            sta[now] = 1, t[now] = 1;
        }
    }
    int now = nxt[N + 1];
    if (now == N + 3)
    {
        cout << "-";
    }
    else
    {
        for (int i = 1; i <= c1; i++)
        {
            cout << now;
            if (i != c1)
            {
                cout << " ";
            }
            now = nxt[now];
        }
    }
    cout << "\n";
    now = nxt[N + 2];
    if (now == N + 4)
    {
        cout << "-";
    }
    else
    {
        for (int i = 1; i <= c2; i++)
        {
            cout << now;
            if (i != c2)
            {
                cout << " ";
            }
            now = nxt[now];
        }
    }
    return 0;
}