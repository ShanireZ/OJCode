#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int l = 1, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2, res;
        cout << mid << endl;
        cin >> res;
        if (res == -1)
        {
            l = mid + 1;
        }
        else if (res == 1)
        {
            r = mid - 1;
        }
        else
        {
            break;
        }
    }
    return 0;
}
// TAG: 交互题 二分