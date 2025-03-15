#include <iostream>
using namespace std;
int a[205], n, pos = 100;
int main()
{
    cin >> n;
    while (n--)
    {
        int opt, x;
        cin >> opt;
        if (opt == 1)
        {
            cin >> x;
            a[++pos] = x;
        }
        else
        {
            cout << a[pos--] << endl;
        }
    }
    return 0;
}