#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    m *= 1.5;
    int scores[n], nums[n];
    memset(scores, 0, sizeof(scores));
    memset(nums, 0, sizeof(nums));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] >> scores[i];
    }
    int j;
    for (int i = 1; i < n; i = j)
    {
        j = i + 1;
        for (; i > 0; i--)
        {
            if ((scores[i - 1] < scores[i]) || ((scores[i - 1] == scores[i]) && (nums[i - 1] > nums[i])))
            {
                int temp = scores[i];
                scores[i] = scores[i - 1];
                scores[i - 1] = temp;
                temp = nums[i];
                nums[i] = nums[i - 1];
                nums[i - 1] = temp;
            }
        }
    }
    int score_min = scores[m - 1];
    int total = m;
    for (int i = m; scores[i] >= score_min; i++)
    {
        total++;
    }
    cout << score_min << " " << total << endl;
    for (int i = 0; i < total; i++)
    {
        cout << nums[i] << " " << scores[i] << endl;
    }
    return 0;
}