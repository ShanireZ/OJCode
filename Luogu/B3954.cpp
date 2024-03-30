#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans = ans * x;
        if (ans > 1000000)
        {
            cout << ">1000000\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}