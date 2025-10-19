#include <algorithm>
#include <iostream>
using namespace std;
int d, x;
int main()
{
    cin >> d;
    for (int i = 1, c = 0; i <= d; i++)
    {
        int v;
        cin >> v;
        if (v == 0)
        {
            x += 100;
        }
        else if (v == 1)
        {
            c++;
            x += (c % 2 == 1 ? 50 : -30);
        }
        cout << x << endl;
    }
    return 0;
}