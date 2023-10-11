#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
vector<int> to[100005];
__int128 p[100005], q[100005], ind[100005], otd[100005];
queue<int> dl;
__int128 gcd(__int128 a, __int128 b)
{
    __int128 r = a % b;
    while (r)
    {
        a = b, b = r;
        r = a % b;
    }
    return b;
}
void opt(__int128 a)
{
    string s;
    while (a)
    {
        s.insert(0, 1, a % 10 + '0');
        a /= 10;
    }
    cout << s << " ";
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int cnt, x;
        cin >> cnt;
        q[i] = 1, p[i] = (i <= m);
        for (int j = 1; j <= cnt; j++)
        {
            cin >> x;
            to[i].push_back(x), ind[x]++, otd[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            dl.push(i);
        }
    }
    while (dl.size())
    {
        int now = dl.front();
        dl.pop();
        if (otd[now] == 0)
        {
            continue;
        }
        __int128 pn = p[now], qn = q[now] * (int)to[now].size();
        __int128 g = gcd(pn, qn);
        pn /= g, qn /= g;
        for (int nxt : to[now])
        {
            ind[nxt]--;
            if (ind[nxt] == 0)
            {
                dl.push(nxt);
            }
            p[nxt] = p[nxt] * qn + pn * q[nxt],
            q[nxt] = q[nxt] * qn;
            g = gcd(p[nxt], q[nxt]);
            p[nxt] /= g, q[nxt] /= g;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (otd[i] == 0)
        {
            opt(p[i]), opt(q[i]), cout << "\n";
        }
    }
    return 0;
}