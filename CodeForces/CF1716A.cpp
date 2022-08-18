#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = (n == 1) ? 2 : (n - 1) / 3 + 1;
        cout << ans << '\n';
    }
    return 0;
}