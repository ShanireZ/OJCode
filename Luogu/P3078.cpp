#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long pre = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long now;
        cin >> now;
        if (now > pre)
        {
            ans += now - pre;
        }
        pre = now;
    }
    cout << ans << endl;
    return 0;
}