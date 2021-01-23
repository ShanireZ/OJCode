#include <iostream>
#include <algorithm>
using namespace std;
int n, ans;
void cnt(int x)
{
    if (x > n)
    {
        return;
    }
    ans = ans * x;
    cnt(x + 1);
}
int main()
{
    cin >> n;
    ans = 1;
    cnt(1);
    cout << ans;
    return 0;
}