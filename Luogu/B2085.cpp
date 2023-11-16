#include <iostream>
using namespace std;
int main()
{
    int cnt = 0, n, x = 1;
    cin >> n;
    while (cnt != n)
    {
        x++;
        int ok = 1;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                ok = 0;
                break;
            }
        }
        cnt += ok;
    }
    cout << x << endl;
    return 0;
}