#include <iostream>
using namespace std;
int trie[500005][2], pos, t[500005], ed[500005];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        int len, now = 0;
        cin >> len;
        for (int j = 1; j <= len; j++)
        {
            int x;
            cin >> x;
            if (trie[now][x] == 0)
            {
                trie[now][x] = ++pos;
            }
            now = trie[now][x];
            t[now]++;
        }
        ed[now]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int len, now = 0, ans = 0, trig = 1;
        cin >> len;
        for (int j = 1; j <= len; j++)
        {
            int x;
            cin >> x;
            if (trig == 0)
            {
                continue;
            }
            if (trie[now][x] == 0)
            {
                trig = 0;
            }
            now = trie[now][x];
            ans += ed[now];
        }
        cout << ans + t[now] - ed[now] << endl;
    }
    return 0;
}