#include <algorithm>
#include <iostream>
using namespace std;
int ans[1000005][2];
int main()
{
    int m, n, nmax;
    cin >> m >> n >> nmax;
    int mm = m / __gcd(m, n), nn = n / __gcd(m, n);
    for (int a = 1; a <= nmax; a++)
    {
        for (int b = a; b <= nmax; b++)
        {
            if ((a * a * a + b * b * b) % mm != 0)
            {
                continue;
            }
            for (int c = 1; c <= nmax; c++)
            {
                for (int d = c; d <= nmax; d++)
                {
                    if ((c * c * c + d * d * d) % nn != 0)
                    {
                        continue;
                    }
                    if ((a * a * a + b * b * b) * nn == (c * c * c + d * d * d) * mm)
                    {
                        cout << a << " " << b << " " << c << " " << d << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No Solution in [1, " << nmax << "] for " << m << "/" << n << ".";
    return 0;
}