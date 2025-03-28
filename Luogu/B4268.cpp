#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, res = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        res = res * i;
        while (res % 10 == 0)
        {
            res /= 10;
        }
        res = res % 1000;
    }
    cout << res % 10 << endl;
    return 0;
}