#include <iostream>
#include <algorithm>
using namespace std;
int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int date1, date2, tot = 0;
    cin >> date1 >> date2;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= month[i]; j++)
        {
            int n1 = i / 10;
            int n2 = i % 10;
            int n3 = j / 10;
            int n4 = j % 10;
            int n = n4 + n3 * 10 + n2 * 100 + n1 * 1000;
            n += n1 * 10000 + n2 * 100000 + n3 * 1000000 + n4 * 10000000;
            if (n >= date1 && n <= date2)
            {
                tot++;
            }
        }
    }
    cout << tot;
    return 0;
}