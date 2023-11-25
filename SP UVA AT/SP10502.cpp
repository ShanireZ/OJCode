#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 305
int trie[MX][5], fail[MX], cnt[MX], h[MX], dp[MX][1005], n, k, root, pos, ans;
string s;
queue<int> q;
void maket()
{
    int now = root, deep = 0;
    for (char c : s)
    {
        int id = c - 'A';
        if (trie[now][id] == 0)
        {
            trie[now][id] = ++pos;
        }
        now = trie[now][id], h[now] = ++deep;
    }
    cnt[now]++;
}
int findpos(int now, int x)
{
    while (now != 0 && trie[now][x] == 0)
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
        for (int i = 0; i < 3; i++)
        {
            int nxt = trie[now][i];
            int f = findpos(fail[now], i);
            if (nxt != 0)
            {
                fail[nxt] = f, q.push(nxt);
                cnt[nxt] += cnt[f];
            }
            else
            {
                trie[now][i] = f;
            }
        }
    }
}
int main()
{
    root = ++pos;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        maket();
    }
    makef();
    for (int len = 1; len <= k; len++)
    {
        for (int now = 1; now <= pos; now++)
        {
            if (h[now] + 1 > len)
            {
                continue;
            }
            for (int x = 0; x < 3; x++)
            {
                int nxt = trie[now][x];
                dp[nxt][len] = max(dp[nxt][len], dp[now][len - 1] + cnt[nxt]);
            }
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        ans = max(ans, dp[i][k]);
    }
    cout << ans << endl;
    return 0;
}