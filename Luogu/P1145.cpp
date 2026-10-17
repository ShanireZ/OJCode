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
            now = (now + m - 1) % (k + k - i); //當前被刪了,可以看作後面都前移了一位,最後一個人刪了
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