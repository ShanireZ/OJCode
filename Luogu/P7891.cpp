#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long n, fj, bs;
vector<long long> a;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            int pos = upper_bound(a.begin(), a.end(), bs) - a.begin(); // 第一个大于的位置
            if (pos == 0)
            {
                bs += a[pos];
                a.erase(a.begin() + pos);
            }
            else
            {
                bs += a[pos - 1];
                a.erase(a.begin() + pos - 1);
            }
        }
        else
        {
            int pos = upper_bound(a.begin(), a.end(), fj) - a.begin(); // 第一个大于的位置
            if (pos == 0)
            {
                fj += a[pos];
                a.erase(a.begin() + pos);
            }
            else
            {
                fj += a[pos - 1];
                a.erase(a.begin() + pos - 1);
            }
        }
    }
    cout << bs << " " << fj << endl;
    return 0;
}