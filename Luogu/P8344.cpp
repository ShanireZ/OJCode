#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        int ok = 0;
        long long cnt = (z * 2 - 1 - x) * x / 2 + z - x;
        if (z >= x && cnt >= y)
        {
            ok = 1;
        }
        if (ok)
        {
            cout << "Renko" << endl;
        }
        else
        {
            cout << "Merry" << endl;
        }
    }
    return 0;
}