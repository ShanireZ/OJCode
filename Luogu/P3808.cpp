#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MX 1000005
int trie[MX][30], vis[MX], fail[MX], pos = 1, ans;
string s;
queue<int> q;
vector<int> rd[MX];
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
    rd[now].push_back(x);
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
            int nxt = trie[now][i];
            int f = findpos(fail[now], i);
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
        for (int id : rd[now])
        {
            if (vis[id] == 0)
            {
                vis[id] = 1, ans++;
            }
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
    searchs();
    cout << ans << endl;
    return 0;
}