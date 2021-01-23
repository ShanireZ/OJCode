#include <iostream>
#include <algorithm>
using namespace std;
int all[1005];
int main()
{
    int n;
    cin >> n;
    int l, r;
    cin >> l;
    for (int i = 2; i <= n; i++)
    {
        cin >> r;
        int c = abs(l - r);
        if (c >= 1 && c <= n - 1)
        {
            all[c] = 1;
        }
        l = r;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (all[i] == 0)
        {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}