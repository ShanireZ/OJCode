#include <iostream>
#include <algorithm>
using namespace std;
int nums[10005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    sort(nums + 1, nums + 1 + n);
    n = unique(nums + 1, nums + 1 + n) - &nums[1];
    if (k <= n)
    {
        cout << nums[k];
    }
    else
    {
        cout << "NO RESULT";
    }
    return 0;
}