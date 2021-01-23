#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int maxn = -1, minn = 5000;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        maxn = max(maxn, num);
        minn = min(minn, num);
    }
    cout << maxn - minn;
    return 0;
}