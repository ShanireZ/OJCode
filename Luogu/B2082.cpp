#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int tot = 0, l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (i % 10 == 2)
        {
            tot++;
        }
        if (i / 10 % 10 == 2)
        {
            tot++;
        }
        if (i / 100 % 10 == 2)
        {
            tot++;
        }
        if (i / 1000 == 2)
        {
            tot++;
        }
    }
    cout << tot << endl;
    return 0;
}