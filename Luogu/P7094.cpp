#include <iostream>
using namespace std;
int main()
{
    //! x(dc−by) = acy ---> abcdxy都为正 所以右边为正 ---> 左边为正 ---> dc-by > 0
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