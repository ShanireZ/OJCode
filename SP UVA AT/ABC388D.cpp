#include <algorithm>
#include <iostream>
using namespace std;
long long cf[500005], v[500005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cf[i] += cf[i - 1];
        v[i] += cf[i];
        long long l = i + 1, r = min(n, i + v[i]);
        cf[l]++, cf[r + 1]--, v[i] -= r - l + 1;
        cout << v[i] << " ";
    }
    return 0;
}