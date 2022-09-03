#include <iostream>
using namespace std;
int nums[1000005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x, l = 1, r = n;
        cin >> x;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            (nums[mid] >= x) ? r = mid - 1 : l = mid + 1;
        }
        if (nums[l] != x)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << l << " ";
        }
    }
    return 0;
}