#include <iostream>
#include <algorithm>
using namespace std;
int nums[200005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    sort(nums + 1, nums + n + 1);
    n = unique(nums + 1, nums + n + 1) - (nums + 1);
    if (n == 1)
    {
        cout << -1 << endl;
    }
    else if (n == 2)
    {
        cout << nums[n] % nums[n - 1] << endl;
    }
    else
    {
        cout << max(nums[n - 2], nums[n] % nums[n - 1]) << endl;
    }
    return 0;
}