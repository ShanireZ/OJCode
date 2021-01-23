#include <iostream>
#include <iomanip>
using namespace std;
int a[15][15];
int main()
{
    int n;
    cin >> n;
    int hang = 1, lie = 1;
    for (int i = 1; i <= n * n;)
    {
        //右
        while (a[hang][lie] == 0 && lie <= n)
        {
            a[hang][lie] = i;
            i++, lie++;
        }
        lie--, hang++;
        //下
        while (a[hang][lie] == 0 && hang <= n)
        {
            a[hang][lie] = i;
            i++, hang++;
        }
        lie--, hang--;
        //左
        while (a[hang][lie] == 0 && lie >= 1)
        {
            a[hang][lie] = i;
            i++, lie--;
        }
        lie++, hang--;
        //上
        while (a[hang][lie] == 0 && hang >= 1)
        {
            a[hang][lie] = i;
            i++, hang--;
        }
        lie++, hang++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
    return 0;
}