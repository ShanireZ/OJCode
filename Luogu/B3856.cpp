#include <algorithm>
#include <iostream>
using namespace std;
long long qzh[100005], qzm[100005], t;
int main()
{
    qzm[0] = qzh[0] = 1;
    for (long long i = 1, x = 11; i <= 100000; i++, x += 10)
    {
        qzm[i] = qzm[i - 1] + x;
        qzh[i] = qzm[i] + qzh[i - 1];
    }
    cin >> t;
    while (t--)
    {
        long long n, a1, b1, c1, a2, b2, c2;
        cin >> n >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        long long t1 = qzh[a1 - 1] + qzm[b1 - 1] + c1 + 1;
        long long t2 = qzh[a2 - 1] + qzm[b2 - 1] + c2 + 1;
        if (t2 < t1)
        {
            t2 += qzh[n - 1];
        }
        cout << t2 - t1 << endl;
    }
    return 0;
}