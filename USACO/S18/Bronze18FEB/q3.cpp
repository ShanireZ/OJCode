#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("taming.in");
ofstream fout("taming.out");
int main()
{
    int n;
    fin >> n;
    int days[n];
    int days_max[n];
    int days_min[n];
    memset(days, 0, sizeof(days));
    memset(days_max, 0, sizeof(days_max));
    memset(days_min, 0, sizeof(days_min));
    for (int i = 0; i < n; i++)
    {
        fin >> days[i];
        days_max[i] = days[i];
        days_min[i] = days[i];
    }
    days[0] = 0;
    days_max[0] = 0;
    days_min[0] = 0;

    if (days[n - 1] == -1)
    {
        days[n - 1] = 0;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (days[i + 1] > 0)
        {
            if (days[i] == -1)
            {
                days[i] = days[i + 1] - 1;
            }
            else if (days[i] != -1)
            {
                if (days[i] != days[i + 1] - 1)
                {
                    fout << -1;
                    return 0;
                }
            }
        }
    }

    int max_d = 0;
    if (days_max[n - 1] == -1)
    {
        days_max[n - 1] = 0;
    }
    if (days_max[n - 1] == 0)
    {
        max_d++;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (days_max[i] == -1)
        {
            days_max[i] = days_max[i + 1] - 1;
            if (days_max[i] <= 0)
            {
                days_max[i] = 0;
                max_d++;
            }
        }
        else if (days_max[i] == 0)
        {
            max_d++;
        }
    }

    int min_d = 0;
    if (days_min[n - 1] == 0)
    {
        min_d++;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (days_min[i] == -1 && days_min[i + 1] > 0)
        {
            days_min[i] = days_min[i + 1] - 1;
        }
        if (days_min[i] == 0)
        {
            min_d++;
        }
    }

    fout << min_d << " " << max_d;
    return 0;
}