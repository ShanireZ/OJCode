#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
int farm_a[11], farm_b[11];
int changes[12101];
int main()
{
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    memset(changes, 0, sizeof(changes));
    for (int i = 0; i < 10; i++)
    {
        fin >> farm_a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        fin >> farm_b[i];
    }
    int cur = 0;
    sort(farm_a, farm_a + 11);
    sort(farm_b, farm_b + 11);
    for (int i1 = 1; i1 < 11; i1++)
    {
        int origin = farm_a[i1];
        int change = farm_a[i1];
        farm_b[0] = farm_a[i1];
        for (int i2 = 0; i2 < 11; i2++)
        {
            if (farm_b[i2] == farm_b[i2 + 1] && i2 + 1 < 11)
            {
                continue;
            }
            change -= farm_b[i2];
            int origin = farm_b[i2];
            farm_a[i1] = farm_b[i2];
            for (int i3 = 1; i3 < 11; i3++)
            {
                if (farm_a[i3] == farm_a[i3 + 1] && i3 + 1 < 11)
                {
                    continue;
                }
                change += farm_a[i3];
                int origin = farm_a[i3];
                farm_b[i2] = farm_a[i3];
                for (int i4 = 0; i4 < 11; i4++)
                {
                    if (farm_b[i4] == farm_b[i4 + 1] && i4 + 1 < 11)
                    {
                        continue;
                    }
                    change -= farm_b[i4];
                    changes[cur++] = change;
                    change += farm_b[i4];
                }
                farm_a[i3] = origin;
                change -= farm_a[i3];
            }
            farm_b[i2] = origin;
            change += farm_b[i2];
        }
        farm_a[i1] = origin;
    }
    sort(changes, changes + cur);
    int times = 1;
    for (int i = 1; i < cur; i++)
    {
        if (changes[i] != changes[i - 1])
        {
            times++;
        }
    }
    fout << times;
    return 0;
}