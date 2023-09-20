#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, a;
        cin >> x >> a;
        while (true)
        {
            cout << x << " ";
            long long now = (x + a) / a;
            if (now == x)
            {
                break;
            }
            else
            {
                x = now;
            }
        }
        cout << endl;
    }
    return 0;
}