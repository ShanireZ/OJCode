#include <cmath>
#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>, unsigned long long> m;
unsigned long long abs(unsigned long long a, unsigned long long b)
{
    return (a > b) ? a - b : b - a;
}
int main()
{
    int n;
    cin >> n;
    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        unsigned long long z;
        cin >> x >> y >> z;
        ans -= abs(m[make_pair(x, y)], m[make_pair(x - 1, y)]) + abs(m[make_pair(x, y)], m[make_pair(x + 1, y)]);
        ans -= abs(m[make_pair(x, y)], m[make_pair(x, y - 1)]) + abs(m[make_pair(x, y)], m[make_pair(x, y + 1)]);
        m[make_pair(x, y)] += z;
        ans += abs(m[make_pair(x, y)], m[make_pair(x - 1, y)]) + abs(m[make_pair(x, y)], m[make_pair(x + 1, y)]);
        ans += abs(m[make_pair(x, y)], m[make_pair(x, y - 1)]) + abs(m[make_pair(x, y)], m[make_pair(x, y + 1)]);
        cout << ans << endl;
    }
    return 0;
}