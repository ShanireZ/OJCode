#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int kc, n, cnt = 0;
    cin >> kc >> n;
    for (int i = 1; i <= n; i++)
    {
        int y;
        cin >> y;
        if (kc >= y)
        {
            kc = kc - y;
        }
        else
        {
            cnt += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}