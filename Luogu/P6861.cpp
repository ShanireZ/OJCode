#include <iostream>
using namespace std;
int main()
{
    long long n, cnt = 0, ans = 0;
    cin >> n;
    while (n)
    {
        cnt++;
        n >>= 1;
    }
    while (cnt)
    {
        ans = (ans << 1) + 1;
        cnt--;
    }
    cout << ans * 2;
    return 0;
}