#include <iostream>
#include <cstring>
using namespace std;
int nums[10];
bool check()
{
    int tot = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (nums[i] > 1)
        {
            return false;
        }
        tot += nums[i];
    }
    if (tot != 9)
    {
        return false;
    }
    return true;
}
int main()
{
    int n1, n2, n3, p = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                memset(nums, 0, sizeof(nums));
                nums[i]++;
                nums[j]++;
                nums[k]++;
                n1 = i * 100 + j * 10 + k;
                n2 = n1 * 2;
                n3 = n1 * 3;
                int x2 = n2 % 10, y2 = n2 / 10 % 10, z2 = n2 / 100;
                nums[x2]++;
                nums[y2]++;
                nums[z2]++;
                int x3 = n3 % 10, y3 = n3 / 10 % 10, z3 = n3 / 100;
                nums[x3]++;
                nums[y3]++;
                nums[z3]++;
                if (check())
                {
                    cout << n1 << " " << n2 << " " << n3 << endl;
                }
            }
        }
    }
    return 0;
}