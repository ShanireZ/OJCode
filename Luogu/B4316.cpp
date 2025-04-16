#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int m, n, ok = 1;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int num, tot = 0;
        cin >> num;
        int x = num;
        while (x)
        {
            tot += x % 10;
            x /= 10;
        }
        if (num % m != 0 && tot % m == 0)
        {
            ok = 0;
            cout << num << endl;
        }
    }
    if (ok)
    {
        cout << "None" << endl;
    }
    return 0;
}