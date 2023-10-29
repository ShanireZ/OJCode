#include <iostream>
using namespace std;
int main()
{
    int a, n, ans = 1;
    cin >> a >> n;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * a;
    }
    cout << ans << endl;
    return 0;
}