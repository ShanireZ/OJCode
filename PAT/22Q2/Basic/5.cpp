#include <algorithm>
#include <iostream>
using namespace std;
int pre[30007], nxt[30007], sta[30007];
int main()
{
    int n, m, t = 0;
    cin >> n >> m;
    int hd = 20000 + 1, lst = 20000 + 3, cnt = 0;
    nxt[hd] = 20000 + 3, pre[lst] = 20000 + 1;
    for (int i = 1; i <= m; i++)
    {
        int now;
        cin >> now;
        if (sta[now])
        {
            pre[nxt[now]] = pre[now], nxt[pre[now]] = nxt[now];
            cnt--;
        }
        else if (cnt == n)
        {
            int x = nxt[hd];
            nxt[hd] = nxt[x], pre[nxt[x]] = hd;
            pre[x] = nxt[x] = 0, cnt--, sta[x] = 0;
            if(t)
            {
                cout << " ";
            }
            cout << x;
            t = 1;
        }
        int x = pre[lst];
        nxt[x] = now, nxt[now] = lst;
        pre[lst] = now, pre[now] = x;
        cnt++, sta[now] = 1;
    }
    return 0;
}