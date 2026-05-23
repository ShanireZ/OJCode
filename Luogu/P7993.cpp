#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long n, ans, a[500005];
vector<int> p[2];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        ch == 'G' ? p[0].push_back(i) : p[1].push_back(i);
        a[i] = (ch == 'H');
    }
    for (int i = 1; i <= n - 2; i++)
    {
        int c0 = 0, c1 = 0;
        for (int j = i; j < i + 3; j++)
        {
            a[j] == 0 ? c0 += 1 : c1 += 1;
        }
        int st = -1;
        if (c0 == 3)
        {
            auto it = lower_bound(p[1].begin(), p[1].end(), i + 3);
            if (it != p[1].end())
            {
                st = *it, c1++;
            }
        }
        else if (c1 == 3)
        {
            auto it = lower_bound(p[0].begin(), p[0].end(), i + 3);
            if (it != p[0].end())
            {
                st = *it, c0++;
            }
        }
        else
        {
            st = i + 2;
        }
        if (st == -1)
        {
            continue;
        }
        if (c0 == 1)
        {
            auto it = lower_bound(p[0].begin(), p[0].end(), st + 1);
            if (it != p[0].end())
            {
                ans += *it - st;
            }
            else
            {
                ans += n - st + 1;
            }
        }
        else if (c1 == 1)
        {
            auto it = lower_bound(p[1].begin(), p[1].end(), st + 1);
            if (it != p[1].end())
            {
                ans += *it - st;
            }
            else
            {
                ans += n - st + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}