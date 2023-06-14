#include <algorithm>
#include <iostream>
using namespace std;
double a[10];
int ids[10];
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (int k = 1; k <= 5; k++)
            {
                if (i == k || j == k)
                {
                    continue;
                }
                for (int l = 1; l <= 5; l++)
                {
                    if (i == l || j == l || k == l)
                    {
                        continue;
                    }
                    if (abs(a[i] / a[j] - a[k] / a[l]) < 0.5)
                    {
                        cnt++;
                        if (cnt == 1)
                        {
                            ids[1] = i, ids[2] = j, ids[3] = k, ids[4] = l;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << " " << ids[1] << " " << ids[2] << " " << ids[3] << " " << ids[4] << "\n";
    return 0;
}