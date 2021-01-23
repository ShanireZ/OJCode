#include <iostream>
#include <algorithm>
using namespace std;
int a[10005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j], a[j - 1]);
                t++;
            }
        }
    }
    cout << t;
    return 0;
}