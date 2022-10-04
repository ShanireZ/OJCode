#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>, unsigned long long> m;
unsigned long long count(unsigned long long a, unsigned long long b)
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
        pair<int, int> c = make_pair(x, y), d = make_pair(x + 1, y), u = make_pair(x - 1, y), l = make_pair(x, y - 1), r = make_pair(x, y + 1);
        ans -= count(m[c], m[d]) + count(m[c], m[u]) + count(m[c], m[l]) + count(m[c], m[r]);
        m[c] += z;
        ans += count(m[c], m[d]) + count(m[c], m[u]) + count(m[c], m[l]) + count(m[c], m[r]);
        cout << ans << "\n";
    }
    return 0;
}