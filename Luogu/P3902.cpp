#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
    int n, p = 1, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (num > a[p - 1])
        {
            a[p++] = num;
            tot++;
        }
        else
        {
            *upper_bound(a + 1, a + p, num) = num;
            // for (int j = 1; j < p; j++)
            // {
            //     if (num < a[j])
            //     {
            //         a[j] = num;
            //         break;
            //     }
            // }
        }
    }
    cout << n - tot;
    return 0;
}