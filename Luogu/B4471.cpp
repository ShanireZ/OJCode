#include <algorithm>
#include <iostream>
using namespace std;
int cnt[1005], n, x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        cnt[x + 500]++;
        if (cnt[x + 500] > n / 2)
        {
            cout << x << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}