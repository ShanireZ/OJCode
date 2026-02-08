#include <algorithm>
#include <iostream>
using namespace std;
int n, a, l[5], cnt[5], y[10005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> y[i];
    }
    cin >> l[3] >> l[2] >> l[1] >> a;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cnt[j] += (y[i] >= l[j]);
        }
    }
    cout << cnt[a] << endl;
    return 0;
}