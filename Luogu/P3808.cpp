#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MAXN 1000005
struct Node
{
    vector<int> sid;
    int fail, fa, chs[26];
};
Node ns[MAXN];
int root, pos, ans, vis[MAXN];
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
    ns[now].sid.push_back(sid);
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
        int id = ns[root].chs[i];
        if (id)
        {
            q.push(id);
            ns[id].fail = root;
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
            for (int i = 0; i < ns[fail].sid.size(); i++)
            {
                ns[nxt].sid.push_back(ns[fail].sid[i]);
            }
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
        for (int j = 0; j < ns[now].sid.size(); j++)
        {
            int sid = ns[now].sid[j];
            if (vis[sid] == 0)
            {
                vis[sid] = 1, ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}