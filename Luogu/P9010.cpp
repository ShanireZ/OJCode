#include <algorithm>
#include <iostream>
using namespace std;
int n, e[200005], t[200005];
int main()
{
    cin >> n;
    int fg = n + 1, fh = n + 1, lg = 0, lh = 0;
    for (int i = 1; i <= n; i++)
    {
        char now;
        cin >> now;
        (now == 'G') ? (fg = min(fg, i), lg = i) : (fh = min(fh, i), lh = i);
        t[i] = now - 'G';
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
    }
    long long totg = (e[fg] >= lg), toth = (e[fh] >= lh);
    int ng = (totg ? fg : n + 1), nh = (toth ? fh : n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (t[i] == 0 && e[i] >= nh && i <= nh)
        {
            ng = i, totg++;
        }
        else if (t[i] == 1 && e[i] >= ng && i <= ng)
        {
            nh = i, toth++;
        }
    }
    cout << totg * toth << "\n";
    return 0;
}