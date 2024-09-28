#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int l, r, h;
};
Node ns[105];
int main()
{
    int n, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].h >> ns[i].l >> ns[i].r;
        ns[i].r--;
    }
    for (int i = 1; i <= n; i++)
    {
        int prel = 0, prer = 0;
        for (int j = 1; j <= n; j++)
        {
            if (ns[i].l >= ns[j].l && ns[i].l <= ns[j].r && ns[i].h > ns[j].h)
            {
                prel = max(prel, ns[j].h);
            }
            if (ns[i].r >= ns[j].l && ns[i].r <= ns[j].r && ns[i].h > ns[j].h)
            {
                prer = max(prer, ns[j].h);
            }
        }
        res += ns[i].h - prel + ns[i].h - prer;
    }
    cout << res << endl;
    return 0;
}