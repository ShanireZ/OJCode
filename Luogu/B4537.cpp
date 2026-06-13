#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, a, b, op, x;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> op >> x;
        if (op == 1)
        {
            cout << (x >= a ? "Y" : "N");
        }
        else
        {
            cout << (x >= b ? "Y" : "N");
        }
    }
    return 0;
}