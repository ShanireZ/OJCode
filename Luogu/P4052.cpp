#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 6005
#define MOD 10007
string s;
int dp[MX][105], trie[MX][30], fail[MX], ed[MX], n, m, root, pos;
queue<int> q;
void maket()
{
    int now = root;
    for (char c : s)
    {
        int id = c - 'A';
        if (trie[now][id] == 0)
        {
            trie[now][id] = ++pos;
        }
        now = trie[now][id];
    }
    ed[now] = 1;
}
int findpos(int now, int x)
{
    if (now != 0 && trie[now][x] == 0)
    {
        now = fail[now];
    }
    return now == 0 ? root : trie[now][x];
}
void makef()
{
    q.push(root);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int nxt = trie[now][i], f = findpos(fail[now], i);
            if (nxt == 0)
            {
                trie[now][i] = f;
            }
            else
            {
                fail[nxt] = f, ed[nxt] |= ed[f], q.push(nxt);
            }
        }
    }
}
int main()
{
    root = ++pos;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        maket();
    }
    makef();
    long long all = 1, tot = 0;
    for (int i = 1; i <= m; i++)
    {
        all = all * 26 % MOD;
    }
    dp[1][0] = 1;
    for (int len = 1; len <= m; len++)
    {
        for (int now = 1; now <= pos; now++)
        {
            for (int id = 0; id < 26; id++)
            {
                int nxt = trie[now][id];
                if (ed[nxt] == 0)
                {
                    dp[nxt][len] = (dp[nxt][len] + dp[now][len - 1]) % MOD;
                }
            }
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        tot = (tot + dp[i][m]) % MOD;
    }
    cout << (all - tot + MOD) % MOD << endl;
    return 0;
}
// TAG: AC自动机 树上DP 动态规划