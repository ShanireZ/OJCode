#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int nums[105];
int st[105];
int main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        nums[i] = i;
        st[i] = i;
    }
    int a1, a2, b1, b2, t = 0, trig = 0;
    cin >> a1 >> a2 >> b1 >> b2;
    while (trig == 0) //找到几次后复原轮回
    {
        reverse(nums + a1, nums + a2 + 1);
        reverse(nums + b1, nums + b2 + 1);
        t++;
        for (int j = 1; j <= n; j++)
        {
            if (nums[j] != st[j])
            {
                break;
            }
            if (j == n)
            {
                trig = 1;
            }
        }
    }
    k %= t;
    for (int i = 1; i <= k; i++)
    {
        reverse(nums + a1, nums + a2 + 1);
        reverse(nums + b1, nums + b2 + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}