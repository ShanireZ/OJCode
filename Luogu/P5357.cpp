#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
string s;
int n, pos, root, ans[200005];
queue<int> q;
struct Node
{
    int fail, chs[26], t, ind;
    vector<int> rd;
};
Node ns[200005];
void init(int now, int sid)
{
    for (int i = 0; i < s.size(); i++)
    {
        int cid = s[i] - 'a';
        if (ns[now].chs[cid] == 0)
        {
            ns[now].chs[cid] = ++pos;
        }
        now = ns[now].chs[cid];
    }
    ns[now].rd.push_back(sid);
}
int findpos(int now, int cid)
{
    while (now != 0 && ns[now].chs[cid] == 0)
    {
        now = ns[now].fail;
    }
    return (now == 0) ? root : ns[now].chs[cid];
}
void makefail()
{
    q.push(root);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int nxt = ns[now].chs[i];
            int fail = findpos(ns[now].fail, i);
            if (nxt != 0)
            {
                ns[nxt].fail = fail, ns[fail].ind += 1;
                q.push(nxt);
            }
            else
            {
                ns[now].chs[i] = fail;
            }
        }
    }
}
void tp()
{
    for (int i = 1; i <= pos; i++)
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
        for (int i = 0; i < ns[now].rd.size(); i++)
        {
            ans[ns[now].rd[i]] += ns[now].t;
        }
        int fail = ns[now].fail;
        ns[fail].t += ns[now].t, ns[fail].ind--;
        if (ns[fail].ind == 0)
        {
            q.push(fail);
        }
    }
}
int main()
{
    root = ++pos;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        init(root, i);
    }
    makefail();
    cin >> s;
    int now = root;
    for (int i = 0; i < s.size(); i++)
    {
        now = findpos(now, s[i] - 'a');
        ns[now].t++;
    }
    tp();
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}