#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 200005
int trie[MX][30], ed[MX], step[MX], fail[MX], ind[MX], pos = 1, ans;
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
                fail[nxt] = f, q.push(nxt), ind[f]++;
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
        step[now]++;
    }
}
void tp()
{
    for (int i = 1; i <= pos; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        int nxt = fail[now];
        ind[nxt]--, step[nxt] += step[now];
        if (ind[nxt] == 0)
        {
            q.push(nxt);
        }
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
    searchs(), tp();
    for (int i = 1; i <= n; i++)
    {
        cout << step[ed[i]] << endl;
    }
    return 0;
}