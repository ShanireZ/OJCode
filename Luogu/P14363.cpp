#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MX 6000005
int tr[MX][30], t[MX], fail[MX], n, m, npos = 1, root = 1;
string s1, s2;
queue<int> q;
void findpos(int &p1, int &p2)
{
    while (s1[p1] == s2[p1])
    {
        p1++;
    }
    while (s1[p2] == s2[p2])
    {
        p2--;
    }
}
void maketree(string s)
{
    int now = root;
    for (char ch : s)
    {
        int id = (ch == '#' ? 26 : ch - 'a');
        if (tr[now][id] == 0)
        {
            tr[now][id] = ++npos;
        }
        now = tr[now][id];
    }
    t[now]++;
}
int findsame(int now, int id)
{
    return now == 0 ? root : tr[now][id];
}
void makefail()
{
    q.push(root);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i <= 26; i++)
        {
            int nxt = tr[now][i], f = findsame(fail[now], i);
            if (nxt == 0)
            {
                tr[now][i] = f;
            }
            else
            {
                t[nxt] += t[f], fail[nxt] = f, q.push(nxt);
            }
        }
    }
}
int searchstr(string s)
{
    int now = root, res = 0;
    for (char ch : s)
    {
        int id = (ch == '#' ? 26 : ch - 'a');
        now = findsame(now, id);
        res += t[now];
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    while (n--)
    {
        cin >> s1 >> s2;
        if (s1 == s2)
        {
            continue;
        }
        int p1 = 0, p2 = (int)s1.size() - 1;
        findpos(p1, p2);
        maketree(s1.substr(0, p1) + "#" + s1.substr(p1, p2 - p1 + 1) + s2.substr(p1, p2 - p1 + 1) + "#" + s1.substr(p2 + 1));
    }
    makefail();
    while (m--)
    {
        cin >> s1 >> s2;
        if (s1.size() != s2.size())
        {
            cout << "0\n";
            continue;
        }
        int p1 = 0, p2 = (int)s1.size() - 1;
        findpos(p1, p2);
        cout << searchstr(s1.substr(0, p1) + "#" + s1.substr(p1, p2 - p1 + 1) + s2.substr(p1, p2 - p1 + 1) + "#" + s1.substr(p2 + 1)) << "\n";
    }
    cout << endl;
    return 0;
}