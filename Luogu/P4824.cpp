#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 1000005
struct Node
{
    int fail, chs[26];
};
Node ns[MX];
queue<int> q;
char ans[MX];
string s, t;
int root, pos, p[MX];
void make_trie()
{
    int now = root;
    for (int i = 0; i < t.size(); i++)
    {
        int cid = t[i] - 'a';
        if (ns[now].chs[cid] == 0)
        {
            ns[now].chs[cid] = ++pos;
        }
        now = ns[now].chs[cid];
    }
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
        if (now != 0)
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
            int fail = find_pos(ns[now].fail, i);
            if (nxt == 0)
            {
                ns[now].chs[i] = fail;
                continue;
            }
            ns[nxt].fail = fail;
            q.push(nxt);
        }
    }
}
int main()
{
    cin >> s >> t;
    root = ++pos;
    make_trie();
    make_fail();
    int apos = 0;
    p[apos] = root;
    for (int i = 0; i < s.size(); i++)
    {
        int now = find_pos(p[apos], s[i] - 'a');
        if (now == pos)
        {
            apos = apos - t.size() + 1;
            continue;
        }
        ans[apos] = s[i];
        p[++apos] = now;
    }
    for (int i = 0; i < apos; i++)
    {
        cout << ans[i];
    }
    return 0;
}