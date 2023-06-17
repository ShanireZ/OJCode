#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, cnt = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        int x = i, tj = 0, to = 0, t = 1;
        while (x)
        {
            t == 1 ? tj += x % 10 : to += x % 10;
            t ^= 1, x /= 10;
        }
        cnt += (tj == to);
    }
    cout << cnt << "\n";
    return 0;
}