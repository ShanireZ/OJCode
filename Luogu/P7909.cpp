#include <iostream>
using namespace std;
int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    if (r - l + 1 >= n)
    {
        cout << n - 1 << endl;
    }
    else
    {
        l %= n, r %= n;
        if (r < l)
        {
            cout << n - 1 << endl;
        }
        else
        {
            cout << r << endl;
        }
    }
    return 0;
}