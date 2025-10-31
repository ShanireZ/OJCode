#include <iostream>
using namespace std;
int main()
{
    long long ans = 0, jc = 1, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        jc *= i;
        ans += jc;
    }
    cout << ans << endl;
    return 0;
}