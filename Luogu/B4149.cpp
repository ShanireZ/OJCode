#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int x, y, z, xx, yy, zz;
};
Node n1, n2;
int main()
{
    cin >> n1.x >> n1.y >> n1.z >> n1.xx >> n1.yy >> n1.zz;
    cin >> n2.x >> n2.y >> n2.z >> n2.xx >> n2.yy >> n2.zz;
    long long a = min(n2.xx, n1.xx) - max(n2.x, n1.x) + 1;
    long long b = min(n2.yy, n1.yy) - max(n2.y, n1.y) + 1;
    long long c = min(n2.zz, n1.zz) - max(n2.z, n1.z) + 1;
    cout << ((a > 0 && b > 0 && c > 0) ? a * b * c : 0) << endl;
    return 0;
}