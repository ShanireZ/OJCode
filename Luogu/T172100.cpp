#include <iostream>
#include <algorithm>
using namespace std;
int ps[100005], gd[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ps[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> gd[i];
    }
    sort(ps + 1, ps + 1 + n);
    sort(gd + 1, gd + 1 + m);
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        if (ps[i] >= gd[pos])
        {
            pos++;
        }
    }
    cout << pos - 1;
    return 0;
}