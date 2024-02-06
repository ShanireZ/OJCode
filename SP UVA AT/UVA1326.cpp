#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string str;
int ct[30], way[30], res[30], n, ans;
void dfs(int now, int v, int cnt)
{
    if (now == n + 1)
    {
        if (v == 0 && ans < cnt)
        {
            ans = cnt;
            for (int i = 1; i <= cnt; i++)
            {
                res[i] = way[i];
            }
        }
        return;
    }
    way[cnt + 1] = now;
    dfs(now + 1, v ^ ct[now], cnt + 1);
    dfs(now + 1, v, cnt);
}
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> str;
            ct[i] = 0;
            for (char c : str)
            {
                ct[i] = ct[i] ^ (1 << (c - 'a'));
            }
        }
        ans = 0;
        dfs(1, 0, 0);
        cout << ans << endl;
        for (int i = 1; i <= ans; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// TAG: 搜索 双向搜索 meet in the middle