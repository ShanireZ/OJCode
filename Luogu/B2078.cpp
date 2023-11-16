#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long m, k, c3 = 0;
    cin >> m >> k;
    for (; m != 0;)
    {
        if (m % 10 == 3)
        {
            c3++;
        }
        m = m / 10;
    }
    if (c3 == k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}