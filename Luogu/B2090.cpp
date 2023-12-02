#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int a[10];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int age;
        cin >> age;
        if (age >= 0 && age <= 18)
        {
            a[1]++;
        }
        else if (age >= 19 && age <= 35)
        {
            a[2]++;
        }
        else if (age >= 36 && age <= 60)
        {
            a[3]++;
        }
        else
        {
            a[4]++;
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        cout << fixed << setprecision(2) << 100.0 * a[i] / n << "%" << endl;
    }
    return 0;
}