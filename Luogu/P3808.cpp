#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 1000005
int trie[MX][30], vis[MX], fail[MX], ed[MX], pos = 1, ans;
string s;
queue<int> q;
void maket(int x)
{
    int now = 1;
    for (char c : s)
    {
        int id = c - 'a';
        if (trie[now][id] == 0)
        {
            trie[now][id] = ++pos;
        }
        now = trie[now][id];
    }
    ed[x] = now;
}
int findpos(int now, int id)
{
    if (now != 0 && trie[now][id] == 0)
    {
        now = fail[now];
    }
    return now == 0 ? 1 : trie[now][id];
}
void makefail()
{
    q.push(1);
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
                fail[nxt] = f, q.push(nxt);
            }
        }
    }
}
void searchs()
{
    int now = 1;
    for (char c : s)
    {
        int id = c - 'a';
        now = findpos(now, id);
        vis[now] = 1;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        maket(i);
    }
    makefail();
    cin >> s;
    searchs();
    for (int i = 1; i <= n; i++)
    {
        ans += vis[ed[i]];
    }
    cout << ans << endl;
    return 0;
}
// 可被课件样例hack