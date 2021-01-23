#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int L;
    cin >> L;
    int tot = 0, num = 0;
    for (int i = 2; tot < L; i++)
    {
        int check = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
        {
            if (tot + i <= L)
            {
                cout << i << endl;
                tot += i;
                num++;
            }
            else
            {
                break;
            }
        }
    }
    cout << num;
    return 0;
}