#include <algorithm>
#include <iostream>
using namespace std;
int c1[30], c2[30], v, n, ans;
int main()
{
    int n;
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        v = v * 345 % 19997;
        c1[v % 26]++;
    }
    for (int i = 1; i <= n; i++)
    {
        v = v * 345 % 19997;
        c2[v % 26]++;
    }
    for (int i = 0; i < 26; i++)
    {
        ans += abs(c1[i] - c2[i]);
    }
    cout << ans / 2 << endl;
    return 0;
}