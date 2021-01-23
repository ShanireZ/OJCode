#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    n = n / 52 / 7;
    for(int x = 100; x >= 1; x--)
    {
        int k = (n - x) / 3;
        if(k > 0 && x + k * 3 == n)
        {
            cout << x << endl << k;
            return 0;
        }
    }
    return 0;
}