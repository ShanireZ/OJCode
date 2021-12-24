#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = n; 1; i++)
    {
        int cnt = 0, x = i;
        while (x)
        {
            if (x % 10 == 3)
            {
                cnt++;
            }
            x /= 10;
        }
        if (cnt == k)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}