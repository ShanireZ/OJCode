#include <algorithm>
#include <iostream>
using namespace std;
int lst[1000005], n, ans = 1e9;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (lst[a] != 0)
        {
            ans = min(ans, i - lst[a] + 1);
        }
        lst[a] = i;
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}