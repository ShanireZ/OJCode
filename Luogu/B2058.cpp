#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, da, db, dc, a = 0, b = 0, c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> da >> db >> dc;
        a += da;
        b += db;
        c += dc;
    }
    cout << a << " " << b << " " << c << " " << a + b + c << endl;
    return 0;
}