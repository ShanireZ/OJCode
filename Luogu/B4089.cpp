#include <algorithm>
#include <iostream>
using namespace std;
int d[505];
int main()
{
    int len, n, m, now = 0, cnt = 0;
    cin >> len >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        if (d[i] - d[now] > m)
        {
            cnt++, now = i - 1;
        }
    }
    if (len - d[now] > m)
    {
        cnt++;
    }
    cout << cnt + 1 << endl;
    return 0;
}