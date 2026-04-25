#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b, ans = 4e18;
    cin >> a >> b;
    for (int fb = 1; fb <= a && fb <= b + b; fb++)
    {
        long long res = abs(fb - b);
        res += min(a % fb, fb - a % fb);
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}