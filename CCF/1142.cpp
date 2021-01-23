#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long m;
    for (; n > 0; n--)
    {
        cin >> m;
        int trig = 1;
        if (m == 1)
        {
            trig = 0;
        }
        else if (m == 2 || m == 3)
        {
        }
        else if ((m + 1) % 6 != 0 && (m - 1) % 6 != 0)
        {
            trig = 0;
        }
        else
        {
            for (int i = 2; i * i <= m; i++)
            {
                if (m % i == 0)
                {
                    trig = 0;
                    break;
                }
            }
        }
        if (trig)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
        cout << endl;
    }
    return 0;
}