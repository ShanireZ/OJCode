#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int nxt[15005], last[15];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(last, 0, sizeof(last));
        memset(nxt, 0, sizeof(nxt));
        int n, q;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            nxt[last[a]] = i;
            last[a] = i;
        }
        cin >> q;
        while (q--)
        {
            int l, r, ans = 0;
            cin >> l >> r;
            while (l <= r)
            {
                if (nxt[l] && nxt[l] <= r)
                {
                    l = nxt[l] + 1;
                }
                else
                {
                    ans++, l++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}