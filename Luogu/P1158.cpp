#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Missile
{
    int disA, disB;
};
struct Node
{
    int x, y;
};
bool cmp(Missile a, Missile b)
{
    return a.disA < b.disA;
}
Missile all[100005];
Node a, b;
int main()
{
    cin >> a.x >> a.y >> b.x >> b.y;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmpX, tmpY;
        cin >> tmpX >> tmpY;
        all[i].disA = pow(tmpX - a.x, 2) + pow(tmpY - a.y, 2);
        all[i].disB = pow(tmpX - b.x, 2) + pow(tmpY - b.y, 2);
    }
    sort(all + 1, all + 1 + n, cmp);
    int tot = 0x3f3f3f3f, pos = 0;
    for (int i = 0; i <= n; i++)
    {
        int ra = all[i].disA, rb = 0;
        if (i + 1 > pos)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (all[j].disB > rb)
                {
                    rb = all[j].disB;
                    pos = j;
                }
            }
        }
        else
        {
            rb = all[pos].disB;
        }
        if (ra + rb < tot)
        {
            tot = ra + rb;
        }
    }
    cout << tot;
    return 0;
}