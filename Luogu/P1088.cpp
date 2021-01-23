#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 1; i <= m; i++)
    {
        next_permutation(nums, nums + n);
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}