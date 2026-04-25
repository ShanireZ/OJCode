#include <algorithm>
#include <iostream>
using namespace std;
int c[100005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        c[l]++, c[r + 1]--;
    }
    for (int i = 1; i <= 100000; i++)
    {
        c[i] += c[i - 1];
    }
    for (int i = n; i >= 0; i--)
    {
        if (c[i] == i)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}