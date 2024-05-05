#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int prim[100005], vis[100005], pos, x;
vector<int> zys;
int main()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; i * prim[j] <= 100000; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    cin >> x;
    int xx = x, zx = 1e9;
    for (int i = 1; i <= pos; i++)
    {
        int cnt = 0;
        while (x % prim[i] == 0)
        {
            x /= prim[i], cnt++;
        }
        if (cnt)
        {
            zys.push_back(cnt), zx = min(zx, prim[i]);
        }
    }
    if (x != 1)
    {
        zys.push_back(1);
    }
    sort(zys.begin(), zys.end());
    int sz = zys.size();
    if (sz == 1) // 只有一种质因数,无法消除
    {
        cout << xx << endl;
    }
    else if (sz % 2 == 1 && zys[sz - 1] == 1) // 有奇数种质因数但个数都是1,只能一对一对消除
    {
        cout << zx << endl;
    }
    else // 肯定能消除完毕
    {
        cout << 1 << endl;
    }
    return 0;
}