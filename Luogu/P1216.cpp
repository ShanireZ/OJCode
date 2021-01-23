#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[2005] = {0};
    for (int i = 1; i <= n; i++) //从上至下逐层累加
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> nums[j + 1000];
            nums[j + 1000] = max(nums[j + 1000] + nums[j], nums[j + 1000] + nums[j - 1]);
        }
        for (int j = 1; j <= i; j++)
        {
            nums[j] = nums[j + 1000];
        }
    }
    int max_v = 0;
    for (int i = 1; i <= n; i++) //选取最后一层最大的
    {
        if (nums[i] > max_v)
        {
            max_v = nums[i];
        }
    }
    cout << max_v;
    return 0;
}