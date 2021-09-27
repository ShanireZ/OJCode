#include <iostream>
using namespace std;
int pre[1000005];
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
        if (i >= k + 1)
        {
            ans = max(pre[i] - pre[i - k - 1], ans);
        }
    }
    cout << ans << endl;
    return 0;
}