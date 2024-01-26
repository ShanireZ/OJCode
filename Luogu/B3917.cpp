#include <algorithm>
#include <iostream>
using namespace std;
int p[1000005], ids[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ids[i];
        p[ids[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        int p0 = p[0], pi = p[i];
        ids[p0] = i, ids[pi] = 0;
        p[0] = pi, p[i] = p0;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ids[i] << " ";
    }
    return 0;
}