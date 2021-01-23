#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    int start, end;
    int result[n + 1][3];
    int guess[n + 1];
    memset(result, 0, sizeof(result));
    memset(guess, 0, sizeof(guess));
    result[0][0] = 1, result[0][1] = 2, result[0][2] = 3;
    for (int i = 1; i <= n; i++)
    {
        cin >> start >> end >> guess[i];
        for (int j = 0; j < 3; j++)
        {
            if (start == result[i - 1][j])
            {
                result[i][j] = end;
            }
            else if (end == result[i - 1][j])
            {
                result[i][j] = start;
            }
            else
            {
                result[i][j] = result[i - 1][j];
            }
        }
    }

    int score[3] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (result[i][j] == guess[i])
            {
                score[j]++;
            }
        }
    }
    sort(score, score + 3);
    cout << score[2];
    return 0;
}