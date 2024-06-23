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
        cout << x << " ";
        while (true)
        {
            long long now = (x + a) / a;
            if (now == x)
            {
                cout << endl;
                break;
            }
            else
            {
                cout << now << " ";
                x = now;
            }
        }
    }
    return 0;
}