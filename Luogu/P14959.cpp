#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        cout << n - 1 << " " << n << " ";
        int l = 1, r = n - 2;
        while (l <= r)
        {
            cout << r << " ";
            if (l != r)
            {
                cout << l << " ";
            }
            l++, r--;
        }
        cout << endl;
    }
    return 0;
}