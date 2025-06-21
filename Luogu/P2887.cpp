#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int l, r;
    bool operator<(const Node &oth) const
    {
        return r < oth.r;
    }
};
Node ns[2505];
struct Fs
{
    int p, c;
    bool operator<(const Fs &oth) const
    {
        return p < oth.p;
    }
};
Fs fs[2505];
int main()
{
    int n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].l >> ns[i].r;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> fs[i].p >> fs[i].c;
    }
    sort(fs + 1, fs + m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (fs[j].c != 0 && fs[j].p >= ns[i].l && fs[j].p <= ns[i].r)
            {
                fs[j].c--, ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}