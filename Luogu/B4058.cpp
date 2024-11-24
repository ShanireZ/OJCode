#include <algorithm>
#include <iostream>
using namespace std;
int nums[10];
int main()
{
    int l, r, ans = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        for (int j = 1, x = i; j <= 6; j++)
        {
            nums[j] = x % 10;
            x /= 10;
        }
        sort(nums + 1, nums + 7);
        if (nums[1] == 0)
        {
            continue;
        }
        int trig = 0;
        for (int j = 2; j < 6 && trig == 0; j++)
        {
            for (int k = j + 1; k <= 6 && trig == 0; k++)
            {
                if (nums[1] + nums[j] > nums[k])
                {
                    int vis[7] = {0, 0, 0, 0, 0, 0, 0}, x = 0, y = 0, z = 0;
                    vis[1] = vis[j] = vis[k] = 1;
                    for (int p = 2; p <= 6 && trig == 0; p++)
                    {
                        if (vis[p] == 0)
                        {
                            x == 0 ? x = p : (y == 0 ? y = p : z = p);
                        }
                    }
                    if (nums[x] + nums[y] > nums[z])
                    {
                        trig = 1;
                    }
                }
            }
        }
        ans += trig;
    }
    cout << ans << endl;
    return 0;
}