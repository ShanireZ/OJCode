#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    double h, tot = 0;
    cin >> h;
    for (int i = 1; i <= 10; i++)
    {
        tot += h;
        if (i == 10)
        {
            cout << tot << endl;
            cout << h / 2 << endl;
        }
        tot += h / 2;
        h = h / 2;
    }
    return 0;
}