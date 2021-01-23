#include <iostream>
#include <algorithm>
using namespace std;
void choose(int t)
{
    if (t == 1)
    {
        cout << "Stan wins" << endl;
    }
    else
    {
        cout << "Ollie wins " << endl;
    }
}
int main()
{
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++)
    {
        int m, n, t = 1;
        cin >> m >> n;
        if (n > m)
        {
            swap(m, n);
        }
        if (n == 0)
        {
            cout << "Stan wins " << endl;
            continue;
        }
        while (true)
        {
            if (m / n >= 2)
            {
                choose(t);
                break;
            }
            m = m % n;
            if (n > m)
            {
                swap(m, n);
            }
            if (n == 0)
            {
                choose(t);
                break;
            }
            t = !t;
        }
    }
    return 0;
}