#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, l;
    cin >> a >> b >> l;
    double minAns = 0x3f3f3f3f;
    int minA = 1, minB = 1;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            int trig = 1;
            for (int k = 2; k <= min(i, j); k++)
            {
                if (i % k == 0 && j % k == 0)
                {
                    trig = 0;
                    break;
                }
            }
            if (trig)
            {
                double tmp = 1.0 * i / j - 1.0 * a / b;
                if (i * b >= j * a && tmp < minAns)
                {
                    minA = i;
                    minB = j;
                    minAns = tmp;
                }
            }
        }
    }
    cout << minA << " " << minB;
    return 0;
}