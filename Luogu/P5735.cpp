#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct Node
{
    double x, y;
};
double makedis(Node a, Node b)
{
    double dx = abs(a.x - b.x);
    double dy = abs(a.y - b.y);
    return sqrt(pow(dx, 2) + pow(dy, 2));
}
int main()
{
    Node a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    double tot = makedis(a, b) + makedis(b, c) + makedis(c, a);
    cout << fixed << setprecision(2) << tot;
    return 0;
}