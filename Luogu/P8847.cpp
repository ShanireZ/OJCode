#include <cmath>
#include <iostream>
using namespace std;
int cz, cf;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        (x == 1) ? cz++ : cf++;
    }
    for (int i = 1; i <= min(cf, cz); i++)
    {
        cout << "1 -1 ";
    }
    if (cz > cf)
    {
        for (int i = 1; i <= cz - cf; i++)
        {
            cout << "1 ";
        }
    }
    else
    {
        for (int i = 1; i <= cf - cz; i++)
        {
            cout << "-1 ";
        }
    }
    return 0;
}