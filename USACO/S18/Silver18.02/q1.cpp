#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    long long x, c;
};
Node rest[100005];
bool cmp(Node a, Node b)
{
    return a.c > b.c;
}
int main()
{
    int l, n, rf, rb;
    cin >> l >> n >> rf >> rb;
    for (int i = 1; i <= n; i++)
    {
        cin >> rest[i].x >> rest[i].c;
    }
    sort(rest + 1, rest + 1 + n, cmp);
    int p = 0;
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (rest[i].x > rest[p].x)
        {
            tot += (rest[i].x - rest[p].x) * (rf - rb) * rest[i].c;
            p = i;
        }
    }
    cout << tot;
    return 0;
}