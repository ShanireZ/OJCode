#include <algorithm>
#include <iostream>
using namespace std;
int nums[1000005];
int main()
{
    int n, p;
    cin >> n >> p;
    if (n * 9 < p)
    {
        cout << 1;
        for (int i = 2; i <= n; i++)
        {
            cout << 0;
        }
        cout << endl;
        return 0;
    }
    int ex = p - 1;
    for (int i = 1; i < n; i++)
    {
        nums[i] = (ex > 9) ? 9 : ex;
        ex -= nums[i];
    }
    nums[n] = ex + 1;
    for (int i = n; i >= 1; i--)
    {
        cout << nums[i];
    }
    cout << endl;
    return 0;
}