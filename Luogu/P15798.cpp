#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int l, r, cnt = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        int x = i;
        while (x % 2 == 0)
        {
            x /= 2;
        }
        while (x % 5 == 0)
        {
            x /= 5;
        }
        cnt += (x == 1);
    }
    cout << cnt << endl;
    return 0;
}