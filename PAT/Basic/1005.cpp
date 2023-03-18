#include <algorithm>
#include <iostream>
using namespace std;
int nums[105], ans[105], vis[10005], pos;
int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int n;
        cin >> n;
        nums[i] = n;
        while (n != 1)
        {
            n = ((n % 2 == 0) ? n / 2 : (n * 3 + 1) / 2);
            if (vis[n])
            {
                break;
            }
            vis[n] = 1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (vis[nums[i]] == 0)
        {
            ans[++pos] = nums[i];
        }
    }
    sort(ans + 1, ans + pos + 1);
    for (int i = pos; i >= 1; i--)
    {
        cout << ans[i];
        if (i != 1)
        {
            cout << " ";
        }
    }
    return 0;
}