#include <iostream>
#include <algorithm>
using namespace std;
int prime[10005];
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= 5000; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = 2; i * j <= 10000; j++)
            {
                prime[i * j] = 1;
            }
        }
    }
    for (int i = 4; i <= n; i += 2)
    {
        int trig = 0;
        for (int a = 2; a < n; a++)
        {
            if (prime[a] == 0)
            {
                for (int b = a; b < n; b++)
                {
                    if (prime[b] == 0 && a + b == i)
                    {
                        cout << i << "=" << a << "+" << b << endl;
                        trig = 1;
                        break;
                    }
                }
            }
            if (trig)
            {
                break;
            }
        }
    }
    return 0;
}