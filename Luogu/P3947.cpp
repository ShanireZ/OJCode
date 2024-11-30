#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    string name;
    int cost, rt;
};
Node ns[24];
int s[4200000];
string res[4200000];
bool cmp(Node a, Node b)
{
    return a.name < b.name;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m, t, tot = 0, pw[24] = {1};
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> ns[i].name >> ns[i].cost >> ns[i].rt;
        tot += ns[i].cost, pw[i + 1] = pw[i] * 2;
    }
    sort(ns, ns + n, cmp);
    if (tot > t)
    {
        cout << "No Answer" << endl;
        return 0;
    }
    int lmt = pw[n] - 1;
    for (int sta = 1; sta <= lmt; sta++)
    {
        s[sta] = -1, tot = 0;
        for (int i = 0, x = sta; x; x /= 2, i++)
        {
            tot += ns[i].cost * (x % 2);
        }
        for (int i = 0, x = sta; x; x /= 2, i++)
        {
            if (x % 2 == 0)
            {
                continue;
            }
            int nws = s[sta - pw[i]] + max(ns[i].rt - tot, 0);
            if (nws > s[sta])
            {
                s[sta] = nws, res[sta] = res[sta - pw[i]] + char(i);
            }
            else if (nws == s[sta])
            {
                res[sta] = min(res[sta], res[sta - pw[i]] + char(i));
            }
        }
    }
    if (s[lmt] < m)
    {
        cout << "No Answer" << endl;
        return 0;
    }
    cout << s[lmt] << endl;
    for (int ch : res[lmt])
    {
        cout << ns[ch].name << endl;
    }
    return 0;
}