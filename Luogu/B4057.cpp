#include <algorithm>
#include <iostream>
using namespace std;
int h[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string op;
        int l, r, k;
        cin >> op >> l >> r;
        if (op == "water")
        {
            for (int j = l; j <= r; j++)
            {
                h[j]++;
            }
        }
        else
        {
            cin >> k;
            int ans = 0;
            for (int j = l; j <= r; j++)
            {
                if (h[j] >= k)
                {
                    ans++, h[j] = 0;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}