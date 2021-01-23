#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int tot = 0, round = 1;
    while (k > 0)
    {
        if (k >= round)
        {
            tot += round * round;
        }
        else
        {
            tot += round * k;
        }
        k -= round;
        round++;
    }
    cout << tot;
    return 0;
}