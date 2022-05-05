#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 300005
struct Node_t
{
    int len, fail, ch[26];
};
Node_t ns[MX];
queue<int> q;
string s, mail;
int root, pos, n, dp[MX];
void maketrie()
{
    int now = root, sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        int cid = s[i] - 'a';
        if (ns[now].ch[cid] == 0)
        {
            ns[now].ch[cid] = ++pos;
        }
        now = ns[now].ch[cid];
    }
    ns[now].len = sz;
}
int findpos(int now, int cid)
{
    while (now != 0 && ns[now].ch[cid] == 0)
    {
        now = ns[now].fail;
    }
    return (now == 0) ? root : ns[now].ch[cid];
}
void makefail()
{
    for (int i = 0; i < 26; i++)
    {
        int now = ns[root].ch[i];
        if (now == 0)
        {
            ns[root].ch[i] = root;
        }
        else
        {
            ns[now].fail = root;
            q.push(now);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int nxt = ns[now].ch[i];
            int fail = findpos(ns[now].fail, i);
            if (nxt == 0)
            {
                ns[now].ch[i] = fail;
            }
            else
            {
                ns[nxt].fail = fail;
                ns[nxt].len = max(ns[nxt].len, ns[fail].len);
                q.push(nxt);
            }
        }
    }
}
int main()
{
    cin >> n >> mail;
    root = ++pos;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        maketrie();
    }
    makefail();
    memset(dp, 0x3f, sizeof(dp));
    int now = root;
    for (int i = 0; i < mail.size(); i++)
    {
        now = ns[now].ch[mail[i] - 'a'];
        int len = ns[now].len;
        if (len == 0)
        {
            continue;
        }
        if (i - len < 0)
        {
            dp[i] = 1;
            continue;
        }
        for (int j = i - len; j < i; j++) //此处可用线段树优化
        {
            dp[i] = min(dp[i], dp[j]);
        }
        if (dp[i] != 0x3f3f3f3f)
        {
            dp[i]++;
        }
    }
    if (dp[mail.size() - 1] == 0x3f3f3f3f)
    {
        dp[mail.size() - 1] = -1;
    }
    cout << dp[mail.size() - 1] << endl;
    return 0;
}