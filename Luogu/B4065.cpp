#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, res = -1;
    cin >> n;
    while (n--)
    {
        long long a, tot = 0;
        cin >> a;
        while (a)
        {
            tot += a % 10;
            a /= 10;
        }
        res = max(res, tot);
    }
    cout << res << endl;
    return 0;
}