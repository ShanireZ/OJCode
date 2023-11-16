#include <algorithm>
#include <iostream>
#include <random>
using namespace std;
int main()
{
    int a, b, c, cnt = 0;
    cin >> a >> b >> c;
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (a * i + b * j == c)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}