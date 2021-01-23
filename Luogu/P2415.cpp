#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    //所有子集元素之和 = 所有元素之和 * 2 ^ (n - 1)
    int tot = 0, cnt = 0, num;
    while (cin >> num)
    {
        tot += num;
        cnt++;
    }
    long long ans = tot * pow(2, cnt - 1);
    cout << ans;
    return 0;
}