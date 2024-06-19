#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int v[4];
double p[4];
int main()
{
    v[1] = 310, v[2] = 210, v[3] = 1e9 + 5;
    p[1] = 3, p[2] = 3.3, p[3] = 4.2;
    for (int i = 1, now = 1; i <= 12; i++)
    {
        int n;
        cin >> n;
        double tot = 0;
        while (n > v[now])
        {
            n -= v[now];
            tot += v[now] * p[now];
            now++;
        }
        tot += n * p[now];
        v[now] -= n;
        cout << fixed << setprecision(1) << tot << endl;
    }
    return 0;
}