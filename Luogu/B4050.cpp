#include <algorithm>
#include <iostream>
using namespace std;
int vis[100005], prim[100005], pos;
int main()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && i * prim[j] <= 100000; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        int h, ans = 100;
        cin >> h;
        for (int i = 0; prim[i] <= h && i <= pos; i++)
        {
            int res = (i != 0), ex = h - prim[i], base = 1;
            while (ex > 0) // 物理和魔法攻击互不占用次数
            {
                ex -= base, res++;
                base <<= 1;
            }
            if (ex == 0)
            {
                ans = min(ans, res);
            }
        }
        cout << (ans == 100 ? -1 : ans) << endl;
    }
    return 0;
}