#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x = i, y = i % 10;
        while (x)
        {
            if (x % 10 != y)
            {
                break;
            }
            x /= 10;
        }
        cnt += (x == 0);
    }
    cout << cnt << endl;
    return 0;
}