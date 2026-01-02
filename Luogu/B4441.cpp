#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int n, x[100005], p[100005];
double fc, qw, tot;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        qw += x[i] * p[i], tot += p[i];
    }
    qw /= tot;
    cout << fixed << setprecision(3) << qw << endl;
    for (int i = 1; i <= n; i++)
    {
        fc += (x[i] - qw) * (x[i] - qw) * p[i];
    }
    fc /= tot;
    cout << fixed << setprecision(3) << fc << endl;
    return 0;
}