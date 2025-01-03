#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, a, b, ans = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        ans += ((i % a == 0) + (i % b == 0) == 1);
    }
    cout << ans << endl;
    return 0;
}