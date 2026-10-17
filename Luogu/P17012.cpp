#include <algorithm>
#include <iostream>
using namespace std;
int n, a[1005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j < i; j++)
        {
            a[i] = max(a[i], a[j] + a[i - j]);
        }
    }
    cout << a[n] << endl;
    return 0;
}