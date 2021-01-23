#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream fin("tttt.in");
ofstream fout("tttt.out");

int main()
{
    char ttt[3][3];
    char result[16];
    int k, sum;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fin >> ttt[i][j];
        }
    }

    k = 0;
    memset(result, 0, sizeof(result));
    for (int i = 0; i < 3; i++)
    {
        if (ttt[i][0] == ttt[i][1] && ttt[i][1] == ttt[i][2])
        {
            result[k++] = ttt[i][0];
        }
        if (ttt[0][i] == ttt[1][i] && ttt[1][i] == ttt[2][i])
        {
            result[k++] = ttt[0][i];
        }
    }
    if (ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2])
    {
        result[k++] = ttt[1][1];
    }
    if (ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0])
    {
        result[k++] = ttt[1][1];
    }
    sort(result, result + k);
    sum = 1;
    for (int i = 1; i < k; i++)
    {
        if (result[i] != result[i - 1])
        {
            sum++;
        }
    }
    if (sum == 1 && result[0] == 0)
    {
        sum = 0;
    }
    fout << sum << endl;

    k = 0;
    memset(result, 0, sizeof(result));
    for (int i = 0; i < 3; i++)
    {
        if (ttt[i][0] == ttt[i][1])
        {
            if (ttt[i][1] != ttt[i][2])
            {
                result[k] = min(ttt[i][0], ttt[i][2]);
                result[k + 1] = max(ttt[i][0], ttt[i][2]);
                k += 2;
            }
        }
        else
        {
            if ((ttt[i][2] == ttt[i][0]) || (ttt[i][2] == ttt[i][1]))
            {
                result[k] = min(ttt[i][0], ttt[i][1]);
                result[k + 1] = max(ttt[i][0], ttt[i][1]);
                k += 2;
            }
        }

        if (ttt[0][i] == ttt[1][i])
        {
            if (ttt[1][i] != ttt[2][i])
            {
                result[k] = min(ttt[0][i], ttt[2][i]);
                result[k + 1] = max(ttt[0][i], ttt[2][i]);
                k += 2;
            }
        }
        else
        {
            if ((ttt[2][i] == ttt[0][i]) || (ttt[2][i] == ttt[1][i]))
            {
                result[k] = min(ttt[0][i], ttt[1][i]);
                result[k + 1] = max(ttt[0][i], ttt[1][i]);
                k += 2;
            }
        }
    }

    if (ttt[0][0] == ttt[1][1])
    {
        if (ttt[1][1] != ttt[2][2])
        {
            result[k] = min(ttt[0][0], ttt[2][2]);
            result[k + 1] = max(ttt[0][0], ttt[2][2]);
            k += 2;
        }
    }
    else
    {
        if ((ttt[2][2] == ttt[0][0]) || (ttt[2][2] == ttt[1][1]))
        {
            result[k] = min(ttt[0][0], ttt[1][1]);
            result[k + 1] = max(ttt[0][0], ttt[1][1]);
            k += 2;
        }
    }

    if (ttt[0][2] == ttt[1][1])
    {
        if (ttt[1][1] != ttt[2][0])
        {
            result[k] = min(ttt[0][2], ttt[2][0]);
            result[k + 1] = max(ttt[0][2], ttt[2][0]);
            k += 2;
        }
    }
    else
    {
        if ((ttt[2][0] == ttt[0][2]) || (ttt[2][0] == ttt[1][1]))
        {
            result[k] = min(ttt[0][2], ttt[1][1]);
            result[k + 1] = max(ttt[0][2], ttt[1][1]);
            k += 2;
        }
    }
    int j;
    for (int i = 2; i < k; i = j)
    {
        j = i + 2;
        for (; i >= 2; i -= 2)
        {
            if ((result[i - 2] > result[i]) || ((result[i - 2] == result[i]) && (result[i - 1] > result[i + 1])))
            {
                int temp = result[i];
                result[i] = result[i - 2];
                result[i - 2] = temp;
                temp = result[i + 1];
                result[i + 1] = result[i - 1];
                result[i - 1] = temp;
            }
        }
    }

    sum = 1;
    for (int i = 2; i < k; i += 2)
    {
        if (result[i] != result[i - 2] || result[i + 1] != result[i - 1])
        {
            sum++;
        }
    }
    if (sum == 1 && result[0] == 0)
    {
        sum = 0;
    }
    fout << sum;
    return 0;
}