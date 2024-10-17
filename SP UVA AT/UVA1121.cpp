#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int n, s;
    while (cin >> n >> s)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int res = n + 1;
        for (int l = 1, r = 0, sum = 0; l <= n; l++)
        {
            while (sum < s && r < n)
            {
                r++;
                sum += a[r];
            }
            if (sum < s)
            {
                break;
            }
            res = min(res, r - l + 1);
            sum -= a[l];
        }
        cout << (res == n + 1 ? 0 : res) << endl;
    }
    return 0;
}