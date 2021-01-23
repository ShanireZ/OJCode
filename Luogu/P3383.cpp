#include <iostream>
using namespace std;
bool check[10000001];
int main()
{
    int n, m;
    cin >> n >> m;
    check[0] = 1, check[1] = 1;
    for (int i = 2; i <= n / 2; i++)
    {
        if (check[i] == 0)
        {
            int ratio = 2;
            while (ratio * i <= n)
            {
                if (check[i * ratio] == 0)
                {
                    check[i * ratio] = 1;
                }
                ratio++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        if (check[temp] == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}