#include <algorithm>
#include <iostream>
using namespace std;
int nums[50];
int main()
{
    int a, b, ans = 0;
    cin >> a >> b;
    while (a <= b)
    {
        int x = a, p = 0, trig = 1;
        while (x)
        {
            nums[++p] = x % 2;
            x /= 2;
        }
        nums[0] = nums[p + 1] = 114514;
        for (int i = 1; i <= p; i++)
        {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            {
                trig = 0;
                break;
            }
        }
        a++, ans += trig;
    }
    cout << ans << endl;
    return 0;
}