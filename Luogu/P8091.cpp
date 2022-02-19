#include <iostream>
using namespace std;
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
        int wa = 0, wb = 0, wc = 0;
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                if (a[i] > b[j])
                {
                    wa++;
                }
                else if (a[i] < b[j])
                {
                    wb++;
                }
            }
        }
        if (wb > wa) // 让a>b
        {
            swap(a, b);
        }
        else if (wa == wb)
        {
            cout << "no" << endl;
            continue;
        }
        int trig = 1;
        for (int p1 = 1; p1 <= 10; p1++)
        {
            for (int p2 = 1; p2 <= 10; p2++)
            {
                for (int p3 = 1; p3 <= 10; p3++)
                {
                    for (int p4 = 1; p4 <= 10; p4++)
                    {
                        int c[5] = {0, p1, p2, p3, p4};
                        wb = wc = 0;
                        for (int i = 1; i <= 4; i++)
                        {
                            for (int j = 1; j <= 4; j++)
                            {
                                if (b[i] > c[j])
                                {
                                    wb++;
                                }
                                else if (b[i] < c[j])
                                {
                                    wc++;
                                }
                            }
                        }
                        if (wc >= wb)
                        {
                            continue;
                        }
                        wa = wc = 0;
                        for (int i = 1; i <= 4; i++)
                        {
                            for (int j = 1; j <= 4; j++)
                            {
                                if (c[i] > a[j])
                                {
                                    wc++;
                                }
                                else if (c[i] < a[j])
                                {
                                    wa++;
                                }
                            }
                        }
                        if (wa >= wc)
                        {
                            continue;
                        }
                        trig = 0;
                        goto check;
                    }
                }
            }
        }
    check:
        if (trig == 1)
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