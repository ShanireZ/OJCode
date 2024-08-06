#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
struct Node
{
    double x, y;
};
Node ns[15];
int n, l;
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    double r = 1.0 * l / n;
    mt19937_64 gen(time(0));
    uniform_real_distribution<double> dn(0, l);
    for (int i = 1; i <= 10000000; i++)
    {
        double x = dn(gen), y = dn(gen);
        int ok = 1;
        for (int j = 1; j <= n; j++)
        {
            double dis = (x - ns[j].x) * (x - ns[j].x) + (y - ns[j].y) * (y - ns[j].y);
            if (r * r > dis)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << x << " " << y << endl;
            return 0;
        }
    }
    cout << "GG" << endl;
    return 0;
}