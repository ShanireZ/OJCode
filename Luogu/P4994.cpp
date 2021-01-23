#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int f0 = 0, f1 = 1, f2;
    for (int i = 2;; i++)
    {
        f2 = (f0 + f1) % m;
        f0 = f1;
        f1 = f2;
        if (f0 == 0 && f1 == 1)
        {
            cout << i - 1;
            break;
        }
    }
    return 0;
}