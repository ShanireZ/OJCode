#include <iostream>
using namespace std;

int main()
{
    int l, r, tot = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 == 2)
            {
                tot++;
            }
            tmp /= 10;
        }
    }
    cout << tot;
    return 0;
}