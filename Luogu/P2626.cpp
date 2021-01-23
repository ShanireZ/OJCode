#include <iostream>
#include <cmath>
using namespace std;
int nums[70000];
int main()
{
    int n;
    cin >> n;
    long long a = 1, b = 1;
    for (int i = 3; i <= n; i++)
    {
        long long c = a + b;
        a = b;
        b = c;
    }
    b = b % (long long)pow(2, 31);
    cout << b << "=";
    for (int i = 2; i <= 35000; i++)
    {
        if (nums[i] == 1)
        {
            continue;
        }
        for (int j = 2; i * j < 70000; j++)
        {
            nums[i * j] = 1;
        }
    }
    int trig = 0;
    for (int i = 2; i < 70000; i++)
    {
        if (b == 1)
        {
            return 0;
        }
        while (nums[i] == 0 && b % i == 0)
        {
            if (trig)
            {
                cout << '*';
            }
            cout << i;
            b /= i;
            trig = 1;
        }
    }
    if(b != 1)
    {
        cout << '*' << b;
    }
    return 0;
}