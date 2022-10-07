#include <iostream>
#include <cstdint>
using namespace std;
int n, q, a[200005];
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) // 修改
        {
            a[x] = y;
        }
        else // 查询
        {
            if (y - x + 1 >= 62)
            {
                cout << "Too large" << endl;
            }
            else
            {
                __int128 s = 1, ans = 1;
                for (int i = x; i <= y; i++)
                {
                    s = s * a[i];
                    ans = max(ans, s);
                }
                s = 1;
                for (int i = y; i >= x; i--)
                {
                    s = s * a[i];
                    ans = max(ans, s);
                }
                if (ans > 1073741824)
                {
                    cout << "Too large" << endl;
                }
                else
                {
                    string x;
                    while (ans)
                    {
                        x.insert(0, 1, '0' + ans % 10);
                        ans /= 10;
                    }
                    cout << x << endl;
                }
            }
        }
    }
    return 0;
}