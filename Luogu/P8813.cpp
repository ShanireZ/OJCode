#include <iostream>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    if (a == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    long long ans = a;
    for (int i = 2; i <= b; i++)
    {
        ans = ans * a;
        if (ans > 1000000000)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}