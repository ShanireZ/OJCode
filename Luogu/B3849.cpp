#include <algorithm>
#include <iostream>
using namespace std;
int nums[10], pos;
int main()
{
    int n, r;
    cin >> n >> r;
    while (n)
    {
        nums[++pos] = n % r;
        n /= r;
    }
    for (int i = pos; i >= 1; i--)
    {
        if (nums[i] > 9)
        {
            cout << char(nums[i] - 10 + 'A');
        }
        else
        {
            cout << nums[i];
        }
    }
    return 0;
}
// TAG: 进制转换 模拟