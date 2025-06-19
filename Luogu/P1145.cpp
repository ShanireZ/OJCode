#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int m = k + 1;
    while (true)
    {
        int trig = 1;
        for (int i = 0, now = 0; i < k; i++)
        {
            now = (now + m - 1) % (k + k - i); //当前被删了,可以看作后面都前移了一位,最后一个人删了
            if (now < k)
            {
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            cout << m << endl;
            break;
        }
        m++;
    }
    return 0;
}