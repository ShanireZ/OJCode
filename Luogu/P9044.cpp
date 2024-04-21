#include <algorithm>
#include <iostream>
using namespace std;
int a[2005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = n - k; i >= 1; i--)
    {
        if (a[i] == a[i + 1])
        {
            k++;
        }
        else
        {
            break;
        }
    }
    cout << k << endl;
    return 0;
}