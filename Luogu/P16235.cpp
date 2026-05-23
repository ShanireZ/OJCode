#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, a, tot = 0, mx = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            tot += a, mx = max(mx, a);
        }
        if (tot % 5 == 0 && tot / 5 >= mx)
        {
            cout << "T" << endl;
        }
        else
        {
            cout << "F" << endl;
        }
    }
    return 0;
}