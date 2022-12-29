#include <cstring>
#include <iostream>
using namespace std;
int a[100005], vis[100005], ans[200005][2];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        int n, k, apos = 0;
        scanf("%d %d", &n, &k);
        k %= n;
        if (k % n == 0)
        {
            printf("%d\n", 0);
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        for (int i = n; i >= 1; i--)
        {
            if (vis[i] == 1)
            {
                continue;
            }
            ans[++apos][0] = n + 1, ans[apos][1] = i;
            a[n + 1] = a[i];
            int now = i, nxt = ((now - k + n) % n == 0) ? n : (now - k + n) % n;
            while (vis[nxt] == 0)
            {
                ans[++apos][0] = now, ans[apos][1] = nxt;
                a[now] = a[nxt], vis[now] = 1;
                now = nxt, nxt = nxt = ((now - k + n) % n == 0) ? n : (now - k + n) % n;
            }
            ans[++apos][0] = now, ans[apos][1] = n + 1;
            a[now] = a[n + 1], vis[now] = 1;
        }
        printf("%d\n", apos);
        for (int i = 1; i <= apos; i++)
        {
            printf("%d %d\n", ans[i][0], ans[i][1]);
        }
    }
    return 0;
}