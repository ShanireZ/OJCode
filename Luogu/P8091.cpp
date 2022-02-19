#include <iostream>
using namespace std;
int judge(int x[], int y[])
{
    int wx = 0, wy = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (x[i] > y[j])
            {
                wx++;
            }
            else if (x[i] < y[j])
            {
                wy++;
            }
        }
    }
    return wx - wy;
}
bool checkc(int a[], int b[])
{
    for (int p1 = 1; p1 <= 10; p1++)
    {
        for (int p2 = 1; p2 <= 10; p2++)
        {
            for (int p3 = 1; p3 <= 10; p3++)
            {
                for (int p4 = 1; p4 <= 10; p4++)
                {
                    int c[5] = {0, p1, p2, p3, p4};
                    int x = judge(b, c);
                    if (x <= 0)
                    {
                        continue;
                    }
                    x = judge(c, a);
                    if (x <= 0)
                    {
                        continue;
                    }
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[5] = {0}, b[5] = {0};
        for (int i = 1; i <= 4; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= 4; i++)
        {
            cin >> b[i];
        }
        int x = judge(a, b);
        if (x < 0)
        {
            swap(a, b);
        }
        if (x == 0 || checkc(a, b) == 0)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
    return 0;
}