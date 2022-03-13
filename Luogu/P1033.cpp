#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    double h, s, v, l, k;
    int n, cnt = 0;
    cin >> h >> s >> v >> l >> k >> n;
    h -= k;
    double t1 = sqrt(h / 5); // 从天花板到h时间
    h += k;
    double t2 = sqrt(h / 5);    // 从天花板到地面时间
    double s1 = s - t1 * v + l; // t1时间内小车能接到什么位置的球 位置上限
    double s2 = s - t2 * v;     // t2时间小车能接到什么位置的球 位置下限
    for (int i = n - 1; i >= 0; i--)
    {
        if ((i + 0.0001 >= s2 && i + 0.0001 <= s1) || (i - 0.0001 >= s2 && i - 0.0001 <= s1))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}