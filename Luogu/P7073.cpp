#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;
struct Node
{
    int v, fa, lc, rc, tag;
};
Node ns[1000005];
int pos, p[100005], num[100005], n, q;
stack<int> stk;
string s;
int main()
{
    getline(cin, s);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'x')
        {
            int x = 0;
            i++;
            while (s[i] >= '0' && s[i] <= '9')
            {
                x = x * 10 + (s[i] - '0');
                i++;
            }
            int now = ++pos;
            p[x] = now;
            ns[now].v = num[x];
            stk.push(now);
        }
        else if (s[i] == '!')
        {
            int x = stk.top();
            stk.pop();
            int now = ++pos;
            ns[now].tag = 3;
            ns[now].lc = x;
            ns[now].v = !ns[x].v;
            ns[x].fa = now;
            stk.push(now);
        }
        else if (s[i] == '|' || s[i] == '&')
        {
            int x1 = stk.top();
            stk.pop();
            int x2 = stk.top();
            stk.pop();
            int now = ++pos;
            ns[now].tag = 1;
            ns[now].v = ns[x1].v & ns[x2].v;
            if (s[i] == '|')
            {
                ns[now].tag = 2;
                ns[now].v = ns[x1].v | ns[x2].v;
            }
            ns[now].lc = x1, ns[now].rc = x2;
            ns[x1].fa = ns[x2].fa = now;
            stk.push(now);
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        int now = p[x];
        int fa = ns[now].fa;
        while (fa != 0)
        {
            int cur = -1;
            if (ns[fa].tag == 1)
            {
                cur = ns[ns[fa].lc + ns[fa].rc - now].v & (!ns[now].v);
            }
            else if (ns[fa].tag == 2)
            {
                cur = ns[ns[fa].lc + ns[fa].rc - now].v | (!ns[now].v);
            }
            if (cur != ns[fa].v)
            {
                now = fa;
                fa = ns[fa].fa;
            }
            else
            {
                break;
            }
        }
        if (fa == 0)
        {
            cout << !ns[pos].v << endl;
        }
        else
        {
            cout << ns[pos].v << endl;
        }
    }
    return 0;
}