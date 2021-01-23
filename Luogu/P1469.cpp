#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, ans = 0, tmp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        ans = ans ^ tmp;
    }
    cout << ans;
    return 0;
}