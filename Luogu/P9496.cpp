#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int cnt[100];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, pos = 0, t1 = 0, t2 = 0;
        cin >> n >> m;
        while (n)
        {
            cnt[++pos] += n % 2;
            n /= 2;
        }
        pos = 0;
        while (m)
        {
            cnt[++pos] -= m % 2;
            m /= 2;
        }
        for (int i = 1; i < 70; i++)
        {
            if (cnt[i] == -1)
            {
                t1 = 1;
            }
            else if (cnt[i] == 1)
            {
                t2 = 1;
            }
        }
        cout << t1 + t2 << "\n";
        memset(cnt, 0, sizeof(cnt));
    }
    return 0;
}