#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        int all[105] = {0};
        int now = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x >= l && x <= r)
            {
                now++;
                all[now] = x;
            }
        }
        sort(all + 1, all + 1 + now);
        int tot = 0, cnt = 0;
        for (int i = 1; i <= now; i++)
        {
            if (tot + all[i] > k)
            {
                break;
            }
            tot += all[i];
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}