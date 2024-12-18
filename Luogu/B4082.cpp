#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans += (b == 0 ? 20 : a);
    }
    cout << ans << endl;
    return 0;
}