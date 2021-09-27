#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int x, y, z, ans = 3;
        cin >> x >> y >> z;
        int a = min(x, min(y, z)), c = max(x, max(y, z));
        int b = x + y + z - a - c;
        if (a == 0 && b == 0)
        {
            ans = 0;
        }
        else if (a == 0 && b == c)
        {
            ans = 1;
        }
        else if ((a == 0 && b != c) || (a == b || b == c || a == c) || a + b == c)
        {
            ans = 2;
        }
        cout << ans << endl;
    }
    return 0;
}