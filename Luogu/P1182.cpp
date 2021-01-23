#include <iostream>
using namespace std;
int line[100005];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> line[i];
    }
    int max_v = 1000000000;
    int min_v = 1;
    while (min_v <= max_v)
    {
        int mid_v = (max_v + min_v) / 2;
        int trig = 1;
        int total = 0;
        int group = 0;
        for (int i = 0; i < n; i++) //超了标准就一组，如果组数多了或者有数比标准大，说明标准定低了
        {
            if (total + line[i] <= mid_v)
            {
                total += line[i];
            }
            else
            {
                group++;
                total = line[i];
            }
            if (line[i] > mid_v || group >= m)
            {
                trig = 0;
                break;
            }
        }
        if (trig == 0) //标准定低了
        {
            min_v = mid_v + 1;
        }
        else //标准高了
        {
            max_v = mid_v - 1;
        }
    }
    cout << min_v;
    return 0;
}