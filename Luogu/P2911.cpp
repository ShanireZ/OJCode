#include <iostream>
using namespace std;
int times[100];
int main()
{
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            for (int k = 1; k <= s3; k++)
            {
                int s = i + j + k;
                times[s]++;
            }
        }
    }
    int ans = 0;
    for (int i = 3; i <= s1 + s2 + s3; i++)
    {
        if (times[i] > times[ans])
        {
            ans = i;
        }
    }
    cout << ans;
    return 0;
}