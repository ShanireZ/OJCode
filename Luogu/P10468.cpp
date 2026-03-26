#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
string s;
unsigned long long hsh[1000005], p[1000005], base = 233;
int main()
{
    int m;
    cin >> s >> m;
    p[0] = 1;
    for (int i = 1; i <= (int)s.size(); i++)
    {
        hsh[i] = hsh[i - 1] * base + s[i - 1];
        p[i] = p[i - 1] * base;
    }
    for (int i = 1; i <= m; i++)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        unsigned long long v1 = hsh[r1] - hsh[l1 - 1] * p[r1 - l1 + 1] + ULONG_LONG_MAX;
        unsigned long long v2 = hsh[r2] - hsh[l2 - 1] * p[r2 - l2 + 1] + ULONG_LONG_MAX;
        cout << (v1 == v2 ? "Yes" : "No") << endl;
    }
    return 0;
}