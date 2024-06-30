#include <algorithm>
#include <iostream>
using namespace std;
int t[100005], a[100005];
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[a[i]]++;
        cnt += (t[a[i]] == 1);
    }
    if (cnt % 2 == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        sort(a + 1, a + 1 + n);
        int x = unique(a + 1, a + 1 + n) - a - 1;
        for (int i = 1; i <= x; i++)
        {
            cout << a[i] << " ";
        }
        for (int i = 1; i <= n; i++)
        {
            while (t[i] > 1)
            {
                cout << i << " ";
                t[i]--;
            }
        }
    }
    return 0;
}
// TAG: 贪心 构造