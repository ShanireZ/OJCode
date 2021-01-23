#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int nums[10005];
int main()
{
    int n;
    cin >> n;
    nums[0] = 1;
    nums[1] = 1;
    for (int i = 2; i <= n / 2; i++)
    {
        if (nums[i] == 0)
        {
            for (int j = 2; i * j <= n; j++)
            {
                nums[i * j] = 1;
            }
        }
    }
    int trig = 1;
    for (int i = 2; i <= n - 2; i++)
    {
        if (nums[i] == 0 && nums[i + 2] == 0)
        {
            cout << i << " " << i + 2 << endl;
            trig = 0;
        }
    }
    if (trig)
    {
        cout << "empty";
    }
    return 0;
}