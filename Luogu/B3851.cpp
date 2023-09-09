#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    char c1, c2;
    int c, t;
};
Node ns[300];
int mp[25][25];
string s, chs = "0123456789ABCDEF";
bool cmp(Node a, Node b)
{
    if (a.t == b.t)
    {
        return a.c < b.c;
    }
    return a.t > b.t;
}
int main()
{
    int n, m;
    cin >> n;
    for (int h = 1; h <= n; h++)
    {
        cin >> s;
        for (int j = 0, l = 1; j < (int)s.size(); j += 2, l++)
        {
            int p1 = 0, p2 = 0;
            while (chs[p1] != s[j])
            {
                p1++;
            }
            while (chs[p2] != s[j + 1])
            {
                p2++;
            }
            int x = p1 * 16 + p2;
            mp[h][l] = x, ns[x].t++;
            ns[x].c1 = s[j], ns[x].c2 = s[j + 1], ns[x].c = x;
        }
    }
    m = (int)s.size() / 2;
    sort(ns, ns + 256, cmp);
    for (int i = 0; i < 16; i++)
    {
        cout << ns[i].c1 << ns[i].c2;
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int pos = 0;
            for (int k = 1; k < 16; k++)
            {
                if (abs(ns[pos].c - mp[i][j]) > abs(ns[k].c - mp[i][j]))
                {
                    pos = k;
                }
            }
            cout << chs[pos];
        }
        cout << endl;
    }
    return 0;
}