#include <algorithm>
#include <iostream>
using namespace std;
int s1[5], s2[5], res;
int main()
{
    cin >> s1[1] >> s1[2] >> s1[3] >> s1[4];
    cin >> s2[1] >> s2[2] >> s2[3] >> s2[4];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (s1[i] > s1[j] && s2[i] < s2[j])
            {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}