#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
int main()
{
    cin >> n;
    for (int i = 101; i <= n; i++)
    {
        int x = i;
        int sum = x % 10, lst = x % 10;
        while (x /= 10)
        {
            sum -= x % 10;
            lst = x % 10;
        }
        sum += lst + lst;
        ans += (sum == 0);
    }
    cout << ans << endl;
    return 0;
}