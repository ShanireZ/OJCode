#include <iostream>
using namespace std;
int tk[10];
int award[10];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 7; i++)
    {
        cin >> tk[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int tot = 0;
        for (int j = 1; j <= 7; j++)
        {
            int num;
            cin >> num;
            for (int k = 1; k <= 7; k++)
            {
                if (tk[k] == num)
                {
                    tot++;
                    break;
                }
            }
        }
        award[tot]++;
    }
    for (int i = 7; i >= 1; i--)
    {
        cout << award[i] << " ";
    }
    return 0;
}