#include <iostream>
#include <cmath>
using namespace std;
long long c[100005];
int main()
{
    int n, m, p1;
    long long s1, s2;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    cin >> m >> p1 >> s1 >> s2;
    c[p1] += s1;
    long long tot1 = 0, tot2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < m)
        {
            tot1 += (m - i) * c[i];
        }
        else
        {
            tot2 += (i - m) * c[i];
        }
    }
    int p = m;
    long long minc = abs(tot1 - tot2);
    for (int i = 1; i <= n; i++)
    {
        long long ex = s2 * abs(m - i);
        if (i < m && minc > abs(ex + tot1 - tot2))
        {
            minc = abs(ex + tot1 - tot2);
            p = i;
        }
        else if (i > m && minc > abs(ex + tot2 - tot1))
        {
            minc = abs(ex + tot2 - tot1);
            p = i;
        }
    }
    cout << p << endl;
    return 0;
}