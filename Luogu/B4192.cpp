#include <algorithm>
#include <iostream>
using namespace std;
long long cnt[100005], m, x, y;
int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> cnt[i];
        cnt[i] += cnt[i - 1];
    }
    cin >> x >> y;
    int l = 2, r = m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        long long n1 = cnt[m] - cnt[mid - 1];
        long long n2 = cnt[mid - 1];
        if (n1 >= x && n1 <= y && n2 >= x && n2 <= y)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << (l > m ? 0 : l) << endl;
    return 0;
}