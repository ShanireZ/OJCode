#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, k, lmt = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        lmt *= n;
    }
    int now = n, cnt = 0;
    while (now <= lmt)
    {
        if (now % k % n == 0)
        {
            cnt++;
        }
        now += 10;
    }
    cout << cnt << endl;
    return 0;
}