#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        unsigned long long a, b, res = 0;
        cin >> a >> b;
        while (a && b)
        {
            if (a == b)
            {
                res += a;
                break;
            }
            if (a < b)
            {
                swap(a, b);
            }
            res += (a / b) * b;
            a %= b;
        }
        cout << res << endl;
    }
    return 0;
}