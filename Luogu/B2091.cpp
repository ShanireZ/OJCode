#include <algorithm>
#include <iostream>
using namespace std;
int a[1005], b[1005];
int main()
{
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        tot = tot + a[i] * b[i];
    }
    cout << tot << endl;
    return 0;
}