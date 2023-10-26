#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int now = n, ans1 = 0, ans2 = 0;
    while (now)
    {
        ans1++;
        if (now % 3 == 1 && ans2 == 0)
        {
            ans2 = ans1;
        }
        now -= ceil(now / 3.0);
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
// TAG: 模拟 数学