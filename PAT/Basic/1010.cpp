#include <iostream>
using namespace std;
int main()
{
    int t, n, ok = 0;
    while (cin >> t >> n)
    {
        if (n * t)
        {
            if (ok)
            {
                cout << " ";
            }
            ok = 1;
            cout << t * n << " " << n - 1;
        }
    }
    if (ok == 0)
    {
        cout << "0 0";
    }
    return 0;
}