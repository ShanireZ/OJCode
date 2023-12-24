#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, f = 1, ans = 0;
    cin >> n;
    if (n < 0)
    {
        f = -1;
        n = -n;
    }
    while (n != 0)
    {
        ans = n % 10 + ans * 10;
        n /= 10;
    }
    cout << ans * f << endl;
    return 0;
}