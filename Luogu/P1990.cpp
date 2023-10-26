#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005];
int main()
{
    int n;
    cin >> n;
    a[1] = 1, a[2] = 2, a[3] = 5;
    for (int i = 4; i <= n; i++)
    {
        a[i] = (2 * a[i - 1] + a[i - 3]) % 10000;
    }
    cout << a[n] << endl;
    return 0;
}