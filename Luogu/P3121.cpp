#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MX 100005
struct Node
{
    int fail, chs[26], ssize;
};
Node ns[MX];
queue<int> q;
char ans[MX];
string s, tmp;
int root, pos, p[MX];
void make_trie(int sid)
{
    int now = root;
    for (int i = 0; i < tmp.size(); i++)
    {
        int cid = tmp[i] - 'a';
        if (ns[now].chs[cid] == 0)
        {
            ns[now].chs[cid] = ++pos;
        }
        now = ns[now].chs[cid];
    }
    ns[now].ssize = tmp.size();
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
            int nxt = ns[now].chs[i], fail = find_pos(ns[now].fail, i);
            if (nxt == 0) // 优化ch 使ch数组可以直接定位到fail目标点
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
    ios::sync_with_stdio(0);
    int n;
    cin >> s >> n;
    root = ++pos;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        make_trie(i);
    }
    make_fail();
    int apos = 0;   // 版本控制 如果删除了一个字符串就回退到最后一个未删除字符的版本
    p[apos] = root; // 第i个字符从哪开始搜
    for (int i = 0; i < s.size(); i++)
    {
        int now = find_pos(p[apos], s[i] - 'a');
        if (ns[now].ssize)
        {
            apos = apos - ns[now].ssize + 1;
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