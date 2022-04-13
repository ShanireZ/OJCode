#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MX 200005
struct Node
{
    vector<int> ids;
    int fa, fail, t, ind, chs[26];
};
Node ns[MX];
int root, pos, times[MX];
string s;
queue<int> q;
void make_trie(int sid)
{
    int now = root;
    for (int i = 0; i < s.size(); i++)
    {
        int cid = s[i] - 'a';
        if (ns[now].chs[cid] == 0)
        {
            ns[now].chs[cid] = ++pos;
            ns[pos].fa = now;
        }
        now = ns[now].chs[cid];
    }
    ns[now].ids.push_back(sid);
}
int find_pos(int now, int cid)
{
    while (now != 0 && ns[now].chs[cid] == 0)
    {
        now = ns[now].fail;
    }
    return (now == 0) ? root : ns[now].chs[cid];
}
void make_fail()
{
    for (int i = 0; i < 26; i++)
    {
        int now = ns[root].chs[i];
        if (now)
        {
            q.push(now);
            ns[now].fail = root;
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int nxt = ns[now].chs[i];
            if (nxt == 0)
            {
                continue;
            }
            q.push(nxt);
            int fail = find_pos(ns[now].fail, i);
            ns[nxt].fail = fail;
            ns[fail].ind++;
        }
    }
}
void tp()
{
    for (int i = root; i <= pos; i++)
    {
        if (ns[i].ind == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < ns[now].ids.size(); i++)
        {
            times[ns[now].ids[i]] += ns[now].t;
        }
        int fail = ns[now].fail;
        ns[fail].t += ns[now].t;
        ns[fail].ind--;
        if (ns[fail].ind == 0)
        {
            q.push(fail);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    root = ++pos;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        make_trie(i);
    }
    make_fail();
    cin >> s;
    int now = root;
    for (int i = 0; i < s.size(); i++)
    {
        now = find_pos(now, s[i] - 'a');
        ns[now].t++;
    }
    tp();
    for (int i = 1; i <= n; i++)
    {
        cout << times[i] << endl;
    }
    return 0;
}