#include <algorithm>
#include <iostream>
using namespace std;
int makeans(int opt, int a, int b)
{
    if (opt == 1)
    {
        return a + b;
    }
    else if (opt == 2)
    {
        return a - b;
    }
    else
    {
        return a * b;
    }
}
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= 3; i++)
    {
        int now = makeans(i, a, b);
        for (int j = 1; j <= 3; j++)
        {
            int nxt = makeans(j, now, c);
            if (nxt == d)
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}