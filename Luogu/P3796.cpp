#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MX 10505
int trie[MX][30], step[MX], fail[MX], ind[MX], cnt[155], pos;
string s, all[155];
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
    while (n)
    {
        memset(trie, 0, sizeof(trie)), memset(fail, 0, sizeof(fail));
        memset(step, 0, sizeof(step)), memset(cnt, 0, sizeof(cnt));
        memset(rd, 0, sizeof(rd)), pos = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            all[i] = s, maket(i);
        }
        makefail();
        cin >> s;
        searchs(), tp();
        int ans = 0;
        for (int i = 1; i <= pos; i++)
        {
            for (int id : rd[i])
            {
                cnt[id] = step[i], ans = max(ans, cnt[id]);
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
        {
            if (cnt[i] == ans)
            {
                cout << all[i] << endl;
            }
        }
        cin >> n;
    }
    return 0;
}