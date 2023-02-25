#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (i * i % n < n / 2.0)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}