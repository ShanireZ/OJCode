#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (x)
        {
            cnt += x % 2;
            x /= 2;
        }
    }
    cout << cnt << " " << cnt % 2 << endl;
    return 0;
}