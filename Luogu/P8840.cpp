#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int a, p;
        cin >> a >> p;
        if (p < 16)
        {
            a -= 10;
        }
        else if (p > 20)
        {
            a -= (p - 20);
        }
        if (a < 0)
        {
            a = 0;
        }
        cout << a << endl;
    }
    return 0;
}