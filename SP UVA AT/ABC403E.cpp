#include <algorithm>
#include <iostream>
using namespace std;
string s;
int q, xpos, ypos, ans, ed[500005], t[500005], nx[500005][26], ny[500005][26];
int dfs(int now, int id)
{
    if (id == (int)s.size())
    {
        int x = t[now];
        t[now] = 0;
        return x;
    }
    if (ny[now][s[id] - 'a'] == 0 || t[now] == 0)
    {
        return 0;
    }
    int x = min(dfs(ny[now][s[id] - 'a'], id + 1), t[now]);
    t[now] -= x;
    return x;
}
int main()
{
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op >> s;
        if (op == 1)
        {
            int now = 0;
            for (char ch : s)
            {
                int c = ch - 'a';
                if (nx[now][c] == 0)
                {
                    nx[now][c] = ++xpos;
                }
                now = nx[now][c];
            }
            ed[now] = 1, ans -= dfs(0, 0);
        }
        else
        {
            int now = 0, ok = 1;
            for (char ch : s)
            {
                int c = ch - 'a';
                if (nx[now][c] == 0)
                {
                    break;
                }
                now = nx[now][c];
                if (ed[now])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                ans++, t[0]++, now = 0;
                for (char ch : s)
                {
                    int c = ch - 'a';
                    if (ny[now][c] == 0)
                    {
                        ny[now][c] = ++ypos;
                    }
                    now = ny[now][c];
                    t[now]++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}