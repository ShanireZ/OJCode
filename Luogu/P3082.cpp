#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
string s, t;
int trie[1005][26], dp[10005][1005], fail[1005], root = 1, pos = 1, ans, len;
queue<int> q;
void init()
{
    int now = root;
    for (int i = 1; i < (int)t.size(); i++)
    {
        int x = t[i] - 'a';
        if (trie[now][x] == 0)
        {
            trie[now][x] = ++pos;
        }
        now = trie[now][x];
    }
}
int findpos(int now, int x)
{
    while (now != 0 && trie[now][x] == 0)
    {
        now = fail[now];
    }
    return now == 0 ? root : trie[now][x];
}
void makefail()
{
    q.push(root);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int f = findpos(fail[now], i);
            if (trie[now][i] == 0)
            {
                trie[now][i] = f;
                continue;
            }
            fail[trie[now][i]] = f, q.push(trie[now][i]);
        }
    }
}
int main()
{
    cin >> s >> t;
    s = "#" + s, t = "#" + t;
    init(), makefail(), len = s.size() - 1;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= pos; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]); // 删除s[i]
            int p = trie[j][s[i] - 'a'];
            if (p != pos)
            {
                dp[i][p] = max(dp[i][p], dp[i - 1][j] + 1); // 保留s[i]
            }
        }
    }
    for (int j = 1; j <= pos; j++)
    {
        ans = max(ans, dp[len][j]);
    }
    cout << len - ans << endl;
    return 0;
}