#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct Node
{
    double x, y;
};
int main()
{
    int n;
    double r;
    cin >> n >> r;
    double tot = 2 * M_PI * r;
    Node a, b, start;
    cin >> a.x >> a.y;
    start = a;
    for (int i = 2; i <= n; i++)
    {
        cin >> b.x >> b.y;
        tot += sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
        a = b;
    }
    tot += sqrt(pow(a.x - start.x, 2) + pow(a.y - start.y, 2));
    cout << fixed << setprecision(2) << tot;
    return 0;
}