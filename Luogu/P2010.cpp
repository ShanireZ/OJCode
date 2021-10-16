#include <iostream>
using namespace std;
int m[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int st, ed, tot = 0;
    cin >> st >> ed;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= m[i]; j++)
        {
            int a = i / 10, b = i % 10, c = j / 10, d = j % 10;
            int data = (d * 1000 + c * 100 + b * 10 + a) * 10000;
            data += a * 1000 + b * 100 + c * 10 + d;
            if (data >= st && data <= ed)
            {
                tot++;
            }
        }
    }
    cout << tot << endl;
    return 0;
}