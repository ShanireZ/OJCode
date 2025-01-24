#include <algorithm>
#include <iostream>
using namespace std;
int a[500005];
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1, j = n / 2 + 1; i <= n / 2 && j <= n; j++)
    {
        if (a[i] * 2 <= a[j])
        {
            cnt++, i++;
        }
    }
    cout << cnt << endl;
    return 0;
}