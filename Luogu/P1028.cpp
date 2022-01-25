#include <iostream>
using namespace std;
int n, ans[1005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            ans[i] += ans[j];
        }
    }
    cout << ans[n] << endl;
    return 0;
}