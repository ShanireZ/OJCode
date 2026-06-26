#include <algorithm>
#include <iostream>
using namespace std;
int n, T;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        int trig = 0, l, r;
        for (int i = 1; i <= n; i++)
        {
            cin >> l >> r;
            if ((l == 0 && r) || (l && r == 0))
            {
                trig = 1;
            }
        }
        cout << (trig ? "Yes" : "No") << endl;
    }
    return 0;
}