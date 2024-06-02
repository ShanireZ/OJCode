#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l <= r)
    {
        int now = (l + r) / 2, ex = 0, sum = 0;
        while (now)
        {
            sum += now, ex += now;
            now = ex / 3, ex %= 3;
        }
        if (sum >= n)
        {
            r = (l + r) / 2 - 1;
        }
        else
        {
            l = (l + r) / 2 + 1;
        }
    }
    cout << l << endl;
    return 0;
}