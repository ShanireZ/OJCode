#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int j;
    sort(nums, nums + n, greater<string>());
    for (int i = 1; i < n; i = j)
    {
        j = i + 1;
        for (; i >= 1; i--)
        {
            int size_pre = nums[i - 1].size();
            int size_cur = nums[i].size();
            if (size_pre > size_cur)
            {
                if (nums[i - 1].find(nums[i]) == 0 && nums[i - 1][size_cur] < nums[i][0])
                {
                    string temp = nums[i - 1];
                    nums[i - 1] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }
    string output;
    for (int i = 0; i < n; i++)
    {
        output += nums[i];
    }
    cout << output;
    return 0;
}