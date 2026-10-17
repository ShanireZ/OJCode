#include <iostream>
using namespace std;
int main()
{
    //! x(dc−by) = acy ---> abcdxy都為正 所以右邊為正 ---> 左邊為正 ---> dc-by > 0
    //! dc > by ---> dc/b > y
    int t;
    cin >> t;
    for (int ts = 1; ts <= t; ts++)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long lmt = d * c / b;
        if (lmt * b != d * c)
        {
            lmt++;
        }
        long long ans = 0;
        for (long long y = 1; y < lmt; y++)
        {
            long long x = a * c * y / (d * c - b * y);
            if (x * (d * c - b * y) == a * c * y)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}